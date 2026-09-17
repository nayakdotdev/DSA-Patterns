/*
Problem: Max Sum Subarray of Size K
Platform: GeeksforGeeks
Link: https://www.geeksforgeeks.org/problems/max-sum-subarray-of-size-k5313/1

Approach:
Use a fixed-size sliding window of size k.
Calculate the sum of the first window, then slide the window
by removing the outgoing element and adding the incoming element.
Track the maximum window sum.

Time: O(n)
Space: O(1)
*/

class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        int low=0,high=k-1,sum=0,res=INT_MIN;
        for(int i=low;i<=high;i++)
        sum+=arr[i];
        while(high<arr.size()){
            res=max(sum,res);
            low++;
            high++;
            if(high==arr.size())
            break;
            sum+=arr[high]-arr[low-1];
        }
        return res;
    }
};