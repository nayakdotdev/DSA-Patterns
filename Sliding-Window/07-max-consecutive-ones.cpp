/*
Problem: Max Consecutive Ones III
Platform: LeetCode
Link: https://leetcode.com/problems/max-consecutive-ones-iii/

Approach:
Use a variable-size sliding window and count the number of 1s.
The number of 0s in the window represents the flips needed.
If the required flips exceed k, shrink the window from the left.
Track the maximum valid window length.

Time: O(n)
Space: O(1)
*/

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int low=0,high=0,res=INT_MIN;
        vector<int> f(2,0);
        for(high=0;high<nums.size();high++){
            f[nums[high]]++;
            int diff=(high-low+1)-f[1];
            while(diff>k){
                f[nums[low]]--;
                low++;
                diff=(high-low+1)-f[1];
            }
            res=max(res,high-low+1);
        }
        return res;
    }
};