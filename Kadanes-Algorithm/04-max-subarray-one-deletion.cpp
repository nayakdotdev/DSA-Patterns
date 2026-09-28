/*
Problem: Maximum Subarray Sum with One Deletion
Platform: LeetCode
Link: https://leetcode.com/problems/maximum-subarray-sum-with-one-deletion/

Approach:
Use a modified Kadane's Algorithm with two states:
one for the maximum subarray sum without deletion and one for the
maximum sum with one deletion. For each element, either extend the
current subarray, start a new one, or delete the current element.

Time: O(n)
Space: O(1)
*/

class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int nd=arr[0],od=INT_MIN,res=arr[0];
        for(int i=1;i<arr.size();i++){
            int pnd=nd,pod=od,v;
            nd=max(nd+arr[i],arr[i]);
            if(pod==INT_MIN)
            v=arr[i];
            else
            v=pod+arr[i];
            od=max(v,pnd);
            res=max(res,max(nd,od));
        }
        return res;
    }
};