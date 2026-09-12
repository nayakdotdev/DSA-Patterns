/*
Problem: Remove Duplicates from Sorted Array
Platform: LeetCode
Link: https://leetcode.com/problems/remove-duplicates-from-sorted-array/

Approach:
Use two pointers to compare the current element with the last unique element.
When a new unique element is found, place it at the next position and increase the count.
Since the array is sorted, duplicates are adjacent.

Time: O(n)
Space: O(1)
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int x=0,k=1,y=1;
        while(y<nums.size()){
            if(nums[y]!=nums[x]){
                nums[++x]=nums[y++];
                k++;
            }
            else
            y++;
        }
        return k;
    }
};