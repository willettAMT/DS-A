#include <cstdlib>
#include <print>
#include <vector>
// #include <algorithm>

using std::vector;
using v_t = vector<int>;

class Solution {
public:
    void merge(v_t& nums1, int m, v_t& nums2, int n) {
        int ptr_1 {m - 1}, ptr_2 {n - 1}, ptr_3 {m + n - 1};

        while (ptr_2 >= 0) {
            if (ptr_1 >= 0 && nums1.at(ptr_1) > nums2.at(ptr_2)) 
                nums1.at(ptr_3--) = nums1.at(ptr_1--);
            else nums1.at(ptr_3--) = nums2.at(ptr_2--); 
        }
    }
};

int main(void) {
    v_t nums1 { 1, 3, 5, 7, 0, 0, 0 }, nums2 { 2, 4, 6 };
    Solution solution;

    solution.merge(nums1, 4, nums2, 3);

    std::print("[");
    for (v_t::iterator it = nums1.begin(); it != nums1.end(); ++it) {
        if (std::next(it) != nums1.end()) 
            std::print("{}, ", *it );
        else std::print("{}", *it );
    }
    std::print("]");
    return EXIT_SUCCESS;
}
