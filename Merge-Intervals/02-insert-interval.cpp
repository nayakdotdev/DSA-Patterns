/*
Problem: Insert Interval
Platform: LeetCode
Link: https://leetcode.com/problems/insert-interval/

Approach:
Insert the new interval at the correct position based on its start
value, then merge all overlapping intervals using the merge intervals
approach.

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
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        bool ins=false;
        for(int i=0;i<intervals.size();i++){
            if(ins==false&&intervals[i][0]>newInterval[0]){
                res.push_back(newInterval);
                ins=true;
            }
            res.push_back({intervals[i][0],intervals[i][1]});
        }
        if(!ins)
        res.push_back(newInterval);
        return merge(res);
    }
};