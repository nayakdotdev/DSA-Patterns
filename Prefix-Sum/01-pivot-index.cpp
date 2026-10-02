/*
Problem: Find Pivot Index
Platform: LeetCode
Link: https://leetcode.com/problems/find-pivot-index/

Approach:
Calculate the total sum of the array first. Traverse the array while
maintaining the sum of elements to the left. For each index, calculate
the right sum using total sum minus the current element and left sum.
If left and right sums are equal, return the index.

Time: O(n)
Space: O(1)
*/

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int ps=0,s=0;
        for(int i:nums)
        s+=i;
        for(int i=0;i<nums.size();i++){
            int ss=s-nums[i]-ps;
            if(ps==ss)
            return i;
            ps+=nums[i];
        }
        return -1;
    }
};