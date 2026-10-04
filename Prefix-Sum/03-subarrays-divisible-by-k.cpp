/*
Problem: Subarray Sums Divisible by K
Platform: LeetCode
Link: https://leetcode.com/problems/subarray-sums-divisible-by-k/

Approach:
Use prefix sum remainders with a frequency map. If two prefix sums
have the same remainder when divided by k, the subarray between them
has a sum divisible by k. Normalize negative remainders to keep them
within the range [0, k-1].

Time: O(n)
Space: O(k)
*/

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int sum=0,res=0;
        unordered_map<int,int> f;
        f[0]=1;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            int r=sum%k;
            if(r<0)
            r+=k;
            res+=f[r];
            f[r]++;
        }
        return res;
    }
};