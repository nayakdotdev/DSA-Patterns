/*
Problem: Contiguous Array
Platform: LeetCode
Link: https://leetcode.com/problems/contiguous-array/

Approach:
Treat 0 as -1 and 1 as +1 by tracking the difference between the
number of zeros and ones. If the same difference appears again, the
subarray between those indices contains an equal number of zeros and
ones. Store the first index of each difference and track the maximum
length.

Time: O(n)
Space: O(n)
*/

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int z=0,o=0,res=0;
        unordered_map<int,int> f;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0)
            z++;
            else
            o++;
            int dif=z-o;
            if(dif==0){
                res=max(res,i+1);
                continue;
            }
            if(f.find(dif)==f.end())
            f[dif]=i;
            else
            res=max(res,i-f[dif]);
        }
        return res;
    }
};