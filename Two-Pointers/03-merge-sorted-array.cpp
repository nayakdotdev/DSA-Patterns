/*
Problem: Merge Sorted Array
Platform: LeetCode
Link: https://leetcode.com/problems/merge-sorted-array/

Approach:
Copy the valid elements of nums into a separate array.
Use two pointers to compare elements from both sorted arrays
and place the smaller element into nums.
Add any remaining elements after one array is exhausted.

Time: O(m + n)
Space: O(m)
*/

class Solution {
public:
    void merge(vector<int>& nums, int m, vector<int>& nums2, int n) {
        vector<int> nums1(m);
        for(int i=0;i<m;i++)
        nums1[i]=nums[i];
        int i=0,j=0,k=0;
        while(i<m&&j<n){
            if(nums1[i]<=nums2[j])
            nums[k++]=nums1[i++];
            else
            nums[k++]=nums2[j++];
        }
        while(i<m)
        nums[k++]=nums1[i++];
        while(j<n)
        nums[k++]=nums2[j++];
    }
};