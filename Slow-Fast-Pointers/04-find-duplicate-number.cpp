/*
Problem: Find the Duplicate Number
Platform: LeetCode
Link: https://leetcode.com/problems/find-the-duplicate-number/

Approach:
Treat the array values as pointers to the next index and use Floyd's
slow and fast pointer algorithm. First, find the meeting point inside
the cycle. Then reset one pointer to the start and move both one step
at a time. Their meeting point is the duplicate number.

Time: O(n)
Space: O(1)
*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int s=0,f=0;
        while(true){
            s=nums[s];
            f=nums[f];
            f=nums[f];
            if(s==f){
                s=0;
                while(s!=f){
                    s=nums[s];
                    f=nums[f];
                }
                return s;
            }
        }
        return 0;
    }
};