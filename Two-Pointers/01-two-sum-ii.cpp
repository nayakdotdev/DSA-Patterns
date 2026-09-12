/*
Problem: Two Sum II - Input Array Is Sorted
Platform: LeetCode
Link: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

Approach:
Use two pointers, one at the beginning and one at the end.
If their sum is smaller than target, move the left pointer forward.
If the sum is greater, move the right pointer backward.
If the sum equals target, return their 1-based indices.

Time: O(n)
Space: O(1)
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i=0,j=numbers.size()-1;
        while(i<j){
            if(numbers[i]+numbers[j]==target)
            return {i+1,j+1};
            else if(numbers[i]+numbers[j]<target)
            i++;
            else
            j--;
        }
        return {};
    }
};