/*
You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, 
representing the number of elements in nums1 and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, but instead be stored inside the array nums1. 
To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, 
and the last n elements are set to 0 and should be ignored. nums2 has a length of n.
*/

class Solution {
public:
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
        std::vector<int> nums1_copy = nums1;
        
        size_t nums1_min_index = 0;
        size_t nums2_min_index = 0;

        size_t target_arr_curr_index = 0;

        while (nums1_min_index < m && nums2_min_index < n) {
            if (nums1_copy[nums1_min_index] <= nums2[nums2_min_index]) {
                nums1[target_arr_curr_index] = nums1_copy[nums1_min_index];
                ++nums1_min_index;
            } else {
                nums1[target_arr_curr_index] = nums2[nums2_min_index];
                ++nums2_min_index;
            }

            ++target_arr_curr_index;
        }

        while (nums1_min_index < m) {
            nums1[target_arr_curr_index] = nums1_copy[nums1_min_index];
            ++nums1_min_index;
            ++target_arr_curr_index;
        }

        while (nums2_min_index < n) {
            nums1[target_arr_curr_index] = nums2[nums2_min_index];
            ++nums2_min_index;
            ++target_arr_curr_index;
        } 
    }
};