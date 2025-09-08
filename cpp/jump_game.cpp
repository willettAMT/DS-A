/*
 
55. Jump Game
Medium
Topics
premium lock icon
Companies
You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.

*/
#include <iostream>
#include <vector>

using std::vector;

class Solution {
    public:
        bool canJump(vector<int>& nums){
            if (nums.empty()) return false;
            else if (nums.size() == 1) return true;

            const int n { (int)nums.size() };
            int i {};
};

int main() {
    vector<int>sample { 2, 5, 0, 0 };
    Solution solution;
    bool answer { solution.canJump(sample) };

    std::cout << "Jump game! ~ ";
    answer ? std::cout << "true" : std::cout << "false";

    return 0;
}
