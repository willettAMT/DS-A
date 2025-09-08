/*
 * 151. Reverse Words in a String
Medium
Topics
premium lock icon
Companies
Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.

 

Example 1:

Input: s = "the sky is blue"
Output: "blue is sky the"
Example 2:

Input: s = "  hello world  "
Output: "world hello"
Explanation: Your reversed string should not contain leading or trailing spaces.
Example 3:

Input: s = "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
*/

#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using std::string;
using std::stringstream;
using std::vector;

// class Solution {
//     public:
//         string reverseWords(string s) {
//             stringstream ss(s);
//             vector<string> tokens;
//             string word, result;
//
//             while (ss >> word) {
//                tokens.push_back(word); 
//             }
//
//             for (int i = tokens.size() -1; i >=0; --i){
//                 result += tokens[i];
//                 if (i > 0) result += " ";
//             }
//
//             return result;
//         }
// };

class Solution {
    public:
        string reverseWords(string s) {
            vector<string> words;
            string word;

            for (char c : s) {
                if (c == ' ') {
                    if (!word.empty()) {
                        words.push_back(std::move(word));  // Move instead of copy
                        word.clear();
                    }
                } else {
                    word += c;
                }
            }
            if (!word.empty()) words.push_back(word);

            string result;
            result.reserve(s.length());  // Pre-allocate memory

            for (int i = words.size() - 1; i >= 0; --i) {
                result += words[i];
                if (i > 0) result += ' ';
            }
            return result;
        };
};

int main() {
    string sample = "the sky is blue";
    Solution solution;
    sample = solution.reverseWords(sample);

    std::cout << sample << std::endl;

    return 0;
}
