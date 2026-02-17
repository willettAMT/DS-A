#include <cstdlib>
#include <string>
#include <print>

using std::string;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= s.size()) return s;

        string ns = "";
        int cycle { (2 * numRows) - 2 },
            len = s.size(), 
            lastRow = numRows - 1;

        for (int row {}; row < numRows; ++row) {
            int i = row, rowTwice = 2 * row;
            bool onDiag { false };
            while (i < len) {
                ns += s[i];
                if (row == 0 || row == lastRow) {
                    i += cycle;
                } else {
                    i += onDiag ? rowTwice : cycle - rowTwice;
                    onDiag = !onDiag;
                }
            }
        }
        return ns;
    }
};

int main (int argc, char **argv) {
  if (argc < 2 || argc > 2) {
    std::println("Must enter number of rows!\n");
    return EXIT_FAILURE;
  }

  Solution solution;
  const string TEST {"PAYPALISHIRING"};
  int rows { std::atoi(argv[1]) };

  string converted { solution.convert(TEST, rows) };
  std::println("\"{}\"", converted);
  return EXIT_SUCCESS;
}
