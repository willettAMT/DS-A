#include <climits>
#include <print>
#include <string>
#include <cstdlib>

using std::string;

class Solution {
  public:
    int myAtoi(string s) {
      int len = s.length(), i {}, sign { 1 };
      long numeric {};

      while(i < len && s[i] == ' ') ++i;

      if (i < len && s[i] == '-') { sign = -1; ++i; }
      else if (i < len && s[i] == '+') { ++i; }

      while (i < len) {
         if(s[i] >= '0' && s[i] <= '9') {
           numeric = numeric * 10 + (s[i] - '0');
           if (sign == -1 && numeric > INT_MAX) return INT_MIN;
           if (sign == 1 && numeric > INT_MAX) return INT_MAX;
           ++i;
         } else return numeric * sign;
      } 
      return numeric * sign;
    }
};

int main (int argc, char **argv) {
  if (argc < 2 || argc > 2) {
    std::println("Must enter string numeric!\n");
    return EXIT_FAILURE;
  }

  Solution solution;
  string test = argv[1];

  int converted { solution.myAtoi(test) };
  std::println("{}", converted);
  return EXIT_SUCCESS;
}
