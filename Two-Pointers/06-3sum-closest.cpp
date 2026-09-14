/*
Problem: 3Sum Closest
Platform: LeetCode
Link: https://leetcode.com/problems/3sum-closest/

Approach:
Sort the array and fix one element at a time.
Use two pointers on the remaining elements to find the sum
closest to the target. Track the sum with the minimum difference
from the target and move the pointers based on the current sum.

Time: O(n^2)
Space: O(1) excluding the sorting space
*/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(begin(nums),end(nums));
        int ans,mdiff=INT_MAX;
        for(int i=0;i<nums.size()-2;i++){
            int l=i+1,r=nums.size()-1;
            while(l<r){
                int s=nums[i]+nums[l]+nums[r],diff=abs(s-target);
                if(mdiff>diff){
                    mdiff=diff;
                    ans=s;
                }
                if(s==target)
                return ans;
                if(s<target)
                l++;
                else
                r--;
            }
        }
        return ans;
    }
};