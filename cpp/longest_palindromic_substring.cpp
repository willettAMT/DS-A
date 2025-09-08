/**
 * 5. Longest Palindromic Substring
Medium
Topics
premium lock iconCompanies
Hint

Given a string s, return the longest

in s.

 

Example 1:

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.

Example 2:

Input: s = "cbbd"
Output: "bb"

 

Constraints:

    1 <= s.length <= 1000
    s consist of only digits and English letters.
*/

// #include <algorithm>
#include <iostream>
#include <string>
#include <vector>
// #include <algorithm>


using std::string;
using std::vector;
using std::cout;
using std::endl;

using dp_t =  vector<vector<bool>>; 

// class Solution {
//     public: 
//         string longestPalindrome(string s) {
//             if (s.length() <= 1) return s;
//
//             int longest {1}, start{}, end{};
//             dp_t dp(s.length(), vector<bool>(s.length(), false)); // dynammic programming table
//
//             for (int i {0}; i < s.length(); ++i) {
//                 dp[i][i] = true; // right end is always true (single char palindrome)
//                 for (int j{0}; j < i; ++j) {
//                    if (s[j] == s[i] && (i - j <= 2 || dp[j+1][i-1])) {
//                        dp[j][i] = true;
//                        int curr = i - j + 1;
//                        if (curr > longest) {
//                            longest = curr;
//                            start = j;
//                            end = i;
//                        }
//                    } 
//                 }
//             }
//             return s.substr(start, end - start + 1);
//         }
// };

class Solution {
public:
    std::string longestPalindrome(std::string s) {
        if (s.length() <= 1) {
            return s;
        }

        auto expand_from_center = [&](int left, int right) {
            while (left >= 0 && right < s.length() && s[left] == s[right]) {
                left--;
                right++;
            }
            return s.substr(left + 1, right - left - 1);
        };

        std::string max_str = s.substr(0, 1);

        for (int i = 0; i < s.length() - 1; i++) {
            std::string odd = expand_from_center(i, i);
            std::string even = expand_from_center(i, i + 1);

            if (odd.length() > max_str.length()) {
                max_str = odd;
            }
            if (even.length() > max_str.length()) {
                max_str = even;
            }
        }

        return max_str;
    }
};

int main(void) {
    Solution solution;
    string hello_for_now = solution.longestPalindrome("aaaaaajkjkjkjkjkjkjkj");
    cout << "output: " << hello_for_now << endl;
    return 0;
}
