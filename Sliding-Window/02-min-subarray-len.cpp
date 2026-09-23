/*
Problem: Minimum Size Subarray Sum
Platform: LeetCode
Link: https://leetcode.com/problems/minimum-size-subarray-sum/

Approach:
Use a variable-size sliding window and maintain the current sum.
Expand the window by moving the right pointer. When the sum reaches
or exceeds the target, shrink the window from the left while updating
the minimum valid length.

Time: O(n)
Space: O(1)
*/

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int low=0,high=0,res=INT_MAX,s=0;
        for(high=0;high<nums.size();high++){
            s+=nums[high];
            while(s>=target){
                res=min(res,high-low+1);
                s-=nums[low++];
            }
        }
        return (res==INT_MAX)?0:res;
    }
};