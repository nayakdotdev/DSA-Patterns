/*
Problem: Smallest Sum Contiguous Subarray
Platform: GeeksforGeeks
Link: https://www.geeksforgeeks.org/problems/smallest-sum-contiguous-subarray/1

Approach:
Use a modified version of Kadane's Algorithm to find the minimum
subarray sum. At each element, either extend the current subarray
or start a new subarray from the current element. Track the minimum
sum found so far.

Time: O(n)
Space: O(1)
*/

class Solution {
  public:
    int minSubarraySum(vector<int> &arr) {
        int bend=arr[0],ans=arr[0];
        for(int i=1;i<arr.size();i++){
            bend=min(bend+arr[i],arr[i]);
            ans=min(bend,ans);
        }
        return ans;
    }
};