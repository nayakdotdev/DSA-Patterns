/*
Problem: Subarray Sum Equals K
Platform: LeetCode
Link: https://leetcode.com/problems/subarray-sum-equals-k/

Approach:
Use prefix sum with a frequency map. For each current prefix sum,
check whether sum - k has appeared before. Each occurrence represents
a subarray whose sum is k. Store the frequency of each prefix sum as
the array is traversed.

Time: O(n)
Space: O(n)
*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum=0,res=0;
        unordered_map<int,int> f;
        f[0]=1;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            res+=f[sum-k];
            f[sum]++;
        }
        return res;
    }
};