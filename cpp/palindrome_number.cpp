#include <cstdlib>
#include <print>

constinit int BASE { 10 };

class Solution {
  public:
    bool isPalindrome(int x) {
      if (x < 0 || (x % 10 == 0 && x != 0)) return false;

      int reversed {};
      while (x > reversed) {
        if (reversed > INT_MAX/10 || reversed < INT_MIN/10) return 0;
        else {
          reversed = reversed * 10 + (x % 10);
          x /= 10;
        }
      }
      return x == reversed || x == reversed / 10;
    }
};

int main (int argc, char **argv) {
  if (argc < 2 || argc > 2) {
    std::println("Must provide integer argument!\n");
    return EXIT_FAILURE;
  }

  int test = std::strtol(argv[1], nullptr, BASE);
  Solution solution;

  bool res { solution.isPalindrome(test) };

  res ? std::println("{} is a palindrome\n", test) 
    : std::println("{} is not a palindrome\n", test);

  return EXIT_SUCCESS;
}
