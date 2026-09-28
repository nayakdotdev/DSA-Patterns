/*
Problem: Maximum Absolute Sum of Any Subarray
Platform: LeetCode
Link: https://leetcode.com/problems/maximum-absolute-sum-of-any-subarray/

Approach:
Use Kadane's Algorithm twice by maintaining both the maximum and
minimum subarray sums ending at the current position. The maximum
absolute sum can come from either the largest positive sum or the
smallest negative sum.

Time: O(n)
Space: O(1)
*/

class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int mx=nums[0],mn=nums[0],res=abs(nums[0]);
        for(int i=1;i<nums.size();i++){
            mx=max(mx+nums[i],nums[i]);
            mn=min(mn+nums[i],nums[i]);
            res=max(res,max(abs(mx),abs(mn)));
        }
        return res;
    }
};