/*
Problem: Interval List Intersections
Platform: LeetCode
Link: https://leetcode.com/problems/interval-list-intersections/

Approach:
Use two pointers to compare intervals from both lists.
If the intervals overlap, add their intersection to the result.
Move the pointer whose interval ends first, since it cannot intersect
with any later interval from the other list.

Time: O(m + n)
Space: O(m + n)
*/

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int i=0,j=0;
        vector<vector<int>> res;
        while(i<firstList.size()&&j<secondList.size()){
            int s1=firstList[i][0],e1=firstList[i][1],s2=secondList[j][0],e2=secondList[j][1];
            if(s1<=s2){
                if(e1>=s2)
                res.push_back({max(s1,s2),min(e1,e2)});
            }
            else{
                if(e2>=s1)
                res.push_back({max(s1,s2),min(e1,e2)});
            }
            if(e1<=e2)
            i++;
            else
            j++;
        }
        return res;
    }
};