/*
Problem: Binary Search
Platform: LeetCode
Link: https://leetcode.com/problems/binary-search/

Approach:
Use binary search on the sorted array. Calculate the middle index
and compare its element with the target. If equal, return the index.
If greater, search the left half; otherwise, search the right half.
Return -1 if the target is not found.

Time: O(log n)
Space: O(1)
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0,h=nums.size()-1;
        while(l<=h){
            int m=l+(h-l)/2;
            if(nums[m]==target)
            return m;
            else if(nums[m]>target)
            h=m-1;
            else
            l=m+1;
        }
        return -1;
    }
};