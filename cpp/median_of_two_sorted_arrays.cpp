#include <algorithm>
#include <cstdlib>
#include <print>
#include <algorithm>
#include <vector>
#include <string>
#include <cstdint>
#include <climits>
#include <cstdlib>

using std::string;
using std::vector;

const vector<int>NUMS1 = { 12, 44, 88, 780};
const vector<int>NUMS2 = { 833, 940, 999 };


// Goal: O(log (m+n))

class Solution {
    public:
        double _findMedianSortedArrays(const vector<int>& nums1, const vector<int>& nums2) {
            int nums1_s = nums1.size(),
                nums2_s = nums2.size();
            
            if (nums1_s > nums2_s) return _findMedianSortedArrays(nums2, nums1);

            int total { nums1_s + nums2_s },
                left { (nums1_s + nums2_s + 1) / 2 },
                low {0}, high{nums1_s};

            while (low <= high) {
                int mid1 {(low + high) >> 1}, mid2 {left - mid1},
                    l1{INT_MIN}, l2{INT_MIN}, r1{INT_MAX}, r2{INT_MAX};

                if (mid1 < nums1_s) r1 = nums1[mid1];
                if (mid2 < nums2_s) r2 = nums2[mid2];
                if (mid1 - 1 >= 0) l1 = nums1[mid1 - 1];
                if (mid2 - 1 >= 0) l2 = nums2[mid2 - 1];

                if (l1 <= r2 && l2 <= r1) {
                    if (total % 2 == 1) return std::max(l1, l2);
                    else return ((double)(std::max(l1, l2) + std::min(r1, r2))) / 2.0;
                }
                else if (l1 > r2) high = mid1 - 1;
                else low = mid1 + 1;
            }

            return 0;
        }

        void printVectors(const vector<int>& to_print){
            if (to_print.empty()) std::print("nothing to print\n");
            std::for_each(to_print.begin(), to_print.end(), [](int val) {std::print("{} ", val);});
            std::print("\n");
        }

        // HFT Supposedly
        double findMedianSortedArrays(const vector<int>& nums1, const vector<int>& nums2) {
            const int m = nums1.size();
            const int n = nums2.size();

            // Ensure we always search on the smaller array to optimize performance
            if (__builtin_expect(m > n, 0)) {
                return findMedianOptimized(nums2, nums1);
            }
            return findMedianOptimized(nums1, nums2);
        }

    private:
        __attribute__((always_inline))
            double findMedianOptimized(const vector<int>& smaller, const vector<int>& larger) {
                const int m = smaller.size();
                const int n = larger.size();
                const int total = m + n;
                const int left_partition_size = (total + 1) >> 1;  // Bit shift for division

                // Direct pointer access for maximum performance
                const int* __restrict arr1 = smaller.data();
                const int* __restrict arr2 = larger.data();

                int low = 0, high = m;

                while (__builtin_expect(low <= high, 1)) {
                    // Bit manipulation to avoid multiplication in mid calculation
                    const int partition1 = low + ((high - low) >> 1);
                    const int partition2 = left_partition_size - partition1;

                    // Branchless sentinel value loading with conditional expressions
                    const int left1 = (partition1 == 0) ? INT_MIN : arr1[partition1 - 1];
                    const int left2 = (partition2 == 0) ? INT_MIN : arr2[partition2 - 1];
                    const int right1 = (partition1 == m) ? INT_MAX : arr1[partition1];
                    const int right2 = (partition2 == n) ? INT_MAX : arr2[partition2];

                    // Check if we found the correct partition
                    if (__builtin_expect(left1 <= right2 && left2 <= right1, 1)) {
                        // Found the correct partition - compute median
                        if (total & 1) {  // Odd total length - bit test instead of modulo
                            return static_cast<double>(std::max(left1, left2));
                        } else {
                            // Even total length - avoid division, use multiplication
                            const int64_t sum = static_cast<int64_t>(std::max(left1, left2)) + 
                                static_cast<int64_t>(std::min(right1, right2));
                            return static_cast<double>(sum) * 0.5;
                        }
                    }

                    // Adjust search boundaries
                    if (left1 > right2) {
                        high = partition1 - 1;
                    } else {
                        low = partition1 + 1;
                    }
                }

                // Should never reach here with valid input
                return 0.0;
            }
};

int main (void) {
    Solution solution;
    solution.printVectors(NUMS1);
    solution.printVectors(NUMS2);
    double median {solution._findMedianSortedArrays(NUMS1, NUMS2)};
    std::print("Median is {}\n", median);
    return EXIT_SUCCESS;
}
/**
 *
 double findMedianSortedArrays(const vector<int>& nums1, const vector<int>& nums2) {
 int nums1_s = nums1.size(),
 nums2_s = nums2.size();

 if (nums1_s > nums2_s) return findMedianSortedArrays(nums2, nums1);

 int total { nums1_s + nums2_s },
 left { (nums1_s + nums2_s + 1) / 2 },
 low = std::max(0, left - nums2_s),
 high = std::min(nums1_s, left);

 while (low <= high) {
 int mid1 {(low + high) >> 1}, mid2 {left - mid1};
// Safe sentinel values
int l1 = (mid1 == 0) ? INT_MIN : nums1[mid1-1];
int l2 = (mid2 == 0) ? INT_MIN : nums2[mid2-1]; 
int r1 = (mid1 == nums1_s) ? INT_MAX : nums1[mid1];
int r2 = (mid2 == nums2_s) ? INT_MAX : nums2[mid2];

if (mid1 < nums1_s) r1 = nums1[mid1];
if (mid2 < nums2_s) r2 = nums2[mid2];
if (mid1 - 1 >= 0) l1 = nums1[mid1 - 1];
if (mid2 - 1 >= 0 && mid2 - 1 < nums2_s) l2 = nums2[mid2 - 1];

if (l1 <= r2 && l2 <= r1) {
if (total % 2 == 1) return std::max(l1, l2);
else return ((double)(std::max(l1, l2) + std::min(r1, r2))) / 2.0;
}
else if (l1 > r2) high = mid1 - 1;
else low = mid1 + 1;
}

return 0;
}
*/
