/*
Problem: Merge Intervals
Platform: LeetCode
Link: https://leetcode.com/problems/merge-intervals/

Approach:
Sort the intervals by their starting points. Keep track of the current
interval and compare it with the next one. If they overlap, extend the
current interval. Otherwise, add the current interval to the result
and start a new one.

Time: O(n log n)
Space: O(n)
*/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> res;
        int s1=intervals[0][0],e1=intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            int s2=intervals[i][0],e2=intervals[i][1];
            if(e1>=s2){
                e1=max(e1,e2);
                continue;
            }
            res.push_back({s1,e1});
            s1=s2;
            e1=e2;
        }
        res.push_back({s1,e1});
        return res;
    }
};