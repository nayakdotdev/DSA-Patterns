/*
Problem: Maximum Product Subarray
Platform: LeetCode
Link: https://leetcode.com/problems/maximum-product-subarray/

Approach:
Maintain both the maximum and minimum product ending at the current
position because multiplying by a negative number can turn the minimum
product into the maximum. At each element, calculate both possible
products and update the maximum subarray product found so far.

Time: O(n)
Space: O(1)
*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mx=nums[0],mn=nums[0],ans=nums[0];
        for(int i=1;i<nums.size();i++){
            int cmx=mx*nums[i],cmn=mn*nums[i];
            mx=max(nums[i],max(cmx,cmn));
            mn=min(nums[i],min(cmx,cmn));
            ans=max(ans,max(mn,mx));
        }
        return ans;
    }
};