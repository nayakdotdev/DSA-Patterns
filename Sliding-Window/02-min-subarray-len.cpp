/*
Problem: Minimum Size Subarray Sum
Platform: LeetCode
Link: https://leetcode.com/problems/minimum-size-subarray-sum/

Approach:
Use a variable-size sliding window to maintain a subarray whose sum
is at least the target. Expand the window by moving the right pointer,
then shrink it from the left while the sum remains valid.
Track the minimum window length.

Time: O(n)
Space: O(1)
*/

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int low=0,high=0,res=INT_MAX,s=0;
        while(high<nums.size()){
            s+=nums[high];
            while(s>=target){
                res=min(res,high-low+1);
                s-=nums[low++];
            }
            high++;
        }
        return (res==INT_MAX)?0:res;
    }
};