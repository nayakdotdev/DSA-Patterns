/*
Problem: Squares of a Sorted Array
Platform: LeetCode
Link: https://leetcode.com/problems/squares-of-a-sorted-array/

Approach:
Separate the negative and non-negative numbers into two arrays.
Square both arrays, reverse the squared negative array, and merge
the two sorted arrays using two pointers.

Time: O(n)
Space: O(n)
*/

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> a,b;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>=0)
            a.push_back(nums[i]);
            else
            b.push_back(nums[i]);
        }
        if(b.size()==0){
            for(int i=0;i<nums.size();i++)
            nums[i]=nums[i]*nums[i];
            return nums;
        }
        if(a.size()==0){
            for(int i=0;i<nums.size();i++)
            nums[i]=nums[i]*nums[i];
            reverse(begin(nums),end(nums));
            return nums;
        }
        int m=a.size(),n=b.size(),i=0,j=0,k=0;
        for(int i=0;i<a.size();i++)
        a[i]=a[i]*a[i];
        for(int i=0;i<b.size();i++)
        b[i]=b[i]*b[i];
        reverse(begin(b),end(b));
        while(i<m&&j<n){
            if(a[i]<=b[j])
            nums[k++]=a[i++];
            else
            nums[k++]=b[j++];
        }
        while(i<m)
        nums[k++]=a[i++];
        while(j<n)
        nums[k++]=b[j++];
        return nums;
    }
};