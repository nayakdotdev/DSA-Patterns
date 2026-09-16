/*
Problem: Sort Colors
Platform: LeetCode
Link: https://leetcode.com/problems/sort-colors/

Approach:
Use three pointers to divide the array into three regions for 0, 1, and 2.
Move through the array with the middle pointer. Swap 0s to the left,
2s to the right, and leave 1s in the middle.

Time: O(n)
Space: O(1)
*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l=0,m=0,h=nums.size()-1;
        while(m<=h){
            if(nums[m]==0){
                swap(nums[l],nums[m]);
                l++;
                m++;
            }
            else if(nums[m]==2){
                swap(nums[m],nums[h]);
                h--;
            }
            else
            m++;
        }
    }
};