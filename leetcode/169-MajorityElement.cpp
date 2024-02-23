/*
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. 
You may assume that the majority element always exists in the array.

Follow-up: Could you solve the problem in linear time and in O(1) space?
*/

class Solution {
public:
    int majorityElement(std::vector<int>& nums) {
        std::unordered_map<int, int> mp;

        for (size_t i = 0; i != nums.size(); ++i) {
            ++mp[nums[i]];
        }

        int ans = nums[0];

        for (size_t i = 0; i != nums.size(); ++i) {
            ans = (mp[ans] < mp[nums[i]]) ? nums[i] : ans; 
        }

        return ans;
    }
};