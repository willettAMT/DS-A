#include <climits>
#include <cstdlib>
#include <print>

class Solution {
public:
  int reverse(int x) {
    int reversed {};

    while (x) {
      if (reversed > INT_MAX/10 || reversed < INT_MIN/10)
        return 0;
      else {
        reversed = reversed * 10 + x % 10;
        x /= 10;
      }
    }
    return reversed;
  }
};

int main (int argc, char **argv) {
  if (argc < 2 || argc > 2) {
    std::println("Must enter number to reverse!\n");
    return EXIT_FAILURE;
  }

  Solution solution;
  int test { std::atoi(argv[1]) };

  int converted { solution.reverse(test) };
  std::println("{}", converted);
  return EXIT_SUCCESS;
}
