/*
Problem: Maximum Subarray
Platform: LeetCode
Link: https://leetcode.com/problems/maximum-subarray/

Approach:
Use Kadane's Algorithm to maintain the maximum subarray sum ending
at the current position. At each element, either extend the current
subarray or start a new subarray from the current element.
Track the maximum sum found so far.

Time: O(n)
Space: O(1)
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int bend=nums[0],ans=nums[0];
        for(int i=1;i<nums.size();i++){
            bend=max(bend+nums[i],nums[i]);
            ans=max(ans,bend);
        }
        return ans;
    }
};