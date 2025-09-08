/**
 * 128. Longest Consecutive Sequence
Medium
Topics
premium lock icon
Companies
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.

 

Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
Example 2:

Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9
Example 3:

Input: nums = [1,0,1,2]
Output: 3
 

Constraints:

0 <= nums.length <= 105
-109 <= nums[i] <= 109
*/

#include <vector>
#include <unordered_set>

using std::vector;
using std::unordered_set;

class Solution {
    public:
        int longestConsecutive(vector<int>& nums){
            if (nums.empty()) return 0;

            unordered_set<int>num_set;
            num_set.reserve(nums.size());

            for (const auto& num : nums) {
                num_set.emplace(num);
            }

            int longest_consecutive {};

            for (const auto& num : num_set){
                if (num_set.find(num-1) == num_set.end()){ // AM I AT THE BEGINNING OF A SUBSEQ?
                    int longest {1}, current {num};

                    const auto end_iter = num_set.end();

                    while (num_set.find(++current) != end_iter) {
                        ++longest;
                    }

                    longest_consecutive = (longest > longest_consecutive) ? longest : longest_consecutive;
                }
            }
            return longest_consecutive;
        }
};
