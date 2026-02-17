#include <print>
#include <vector>

using std::vector;
using _subsets_ = vector<vector<int>>;

class Solution {
public:
    _subsets_ subsets(vector<int>& nums) {
        _subsets_ sets {{}};
        for (int num : nums) {
            int n = sets.size();
            for (int i {}; i < n; ++i) {
                sets.push_back(sets[i]);
                sets.back().push_back(num);
            }
        }
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
};

int main (int argc, char **argv) {
  Solution solution;

  vector<int> test {1, 2, 3};
  _subsets_ res { solution.subsets(test) };
  solution.print(res);

  return EXIT_SUCCESS;
}
