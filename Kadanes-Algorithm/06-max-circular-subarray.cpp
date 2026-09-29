/*
Problem: Maximum Sum Circular Subarray
Platform: LeetCode
Link: https://leetcode.com/problems/maximum-sum-circular-subarray/

Approach:
Use Kadane's Algorithm to find both the maximum and minimum subarray
sums along with the total array sum. The maximum circular sum is either
the normal maximum subarray sum or the total sum minus the minimum
subarray sum. If all elements are negative, return the maximum element.

Time: O(n)
Space: O(1)
*/

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int mx=nums[0],cmx=nums[0],mn=nums[0],cmn=nums[0],ts=nums[0];
        for(int i=1;i<nums.size();i++){
            ts+=nums[i];
            cmx=max(cmx+nums[i],nums[i]);
            cmn=min(cmn+nums[i],nums[i]);
            mx=max(mx,cmx);
            mn=min(mn,cmn);
        }
        if(mx<0)
        return mx;
        return max(mx,ts-mn);
    }
};