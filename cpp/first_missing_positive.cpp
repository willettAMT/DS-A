#include <print>
#include <cstdlib>
#include <vector>

class Solution {
public:
    int firstMissingPositive(std::vector<int>& nums) {
        const int n = nums.size();
        int i {0};
        while (i < n){
            if (nums[i] <= 0) i++;
            else if (
                nums[i]<=0 
                || nums[i]>n
                || nums[i]==i+1 
                || nums[nums[i] -1] == nums[i]) i++;
            else std::swap(nums[i], nums[nums[i] - 1]); 
        }
        for(i = 1; i <= n; ++i){
            if (nums[i-1] != i) return i;
        }
        return n + 1;
    }
};

int main (void) {
    std::vector<int> test_case {1,2,3,4,6};
    Solution solution;
    int integer { solution.firstMissingPositive(test_case) };
    std::println("{{1,2,3,4,6}}");
    std::println("\n\nfirst missing positive is {}", integer);

    return EXIT_SUCCESS;
}
