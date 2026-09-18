/*
Problem: Fruit Into Baskets
Platform: LeetCode
Link: https://leetcode.com/problems/fruit-into-baskets/

Approach:
Use a variable-size sliding window with a frequency map.
Expand the window while adding fruit types. If the window contains
more than two distinct fruit types, shrink it from the left until
only two types remain. Track the maximum valid window length.

Time: O(n)
Space: O(1)
*/

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> mp;
        int low=0,high=0,res=INT_MIN;
        for(high=0;high<fruits.size();high++){
            mp[fruits[high]]++;
            while(mp.size()>2){
                mp[fruits[low]]--;
                if(mp[fruits[low]]==0)
                mp.erase(fruits[low]);
                low++;
            }
            res=max(res,high-low+1);
        }
        return (res==INT_MIN)?-1:res;
    }
};