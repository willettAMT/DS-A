#include <print>
#include <algorithm>
#include <vector>

using std::vector;
using _subsets_ = vector<vector<int>>;

class Solution {
public:
    _subsets_ subsets(vector<int>& nums) {
      std::sort(nums.begin(), nums.end());
      _subsets_ sets;
      vector<int> curr;
      backtrack(nums, 0, curr, sets);
      return sets;
    }

    void print(_subsets_ &subsets){
      std::print("{} ", '[');
      for (size_t i = 0; i < subsets.size(); ++i) {
        std::print("{} ", '[');
        for (size_t j = 0; j < subsets[i].size(); ++j) {
          if (j < subsets[i].size() - 1) {
            std::print("{}, ", subsets[i][j]);
          } else std::print("{} ", subsets[i][j]); 
        }
        if (i < subsets.size() - 1) {
          std::print("{}, ", ']');
        } else std::print("{} ", ']');
      }
    }

private:
    void backtrack(
        vector<int>& nums, int start,
        vector<int>& current, _subsets_ &result
        ) {
      result.push_back(current);

      int size = nums.size();
      for (int i = start; i < size; ++i) {
        if (i > start && nums[i] == nums[i-1]) continue;
        current.push_back(nums[i]);
        backtrack(nums, i+1, current, result);
        current.pop_back();
      }
    }
};

int main (int argc, char **argv) {
  Solution solution;

  // vector<int> test {1, 2, 3};
  vector<int> test {1, 2, 2};
  _subsets_ res { solution.subsets(test) };
  solution.print(res);

  return EXIT_SUCCESS;
}
