/*
Problem: Check if Any Two Intervals Overlap
Platform: GeeksforGeeks
Link: https://www.geeksforgeeks.org/dsa/check-if-any-two-intervals-overlap-among-a-given-set-of-intervals/

Approach:
Sort the intervals by their starting points. Compare each interval
with the previous one. If the current interval starts before or when
the previous interval ends, an overlap exists.

Time: O(n log n)
Space: O(1) excluding sorting space
*/

class Solution {
  public:
    bool isIntersect(vector<vector<int>> intervals) {
        sort(begin(intervals),end(intervals));
        int s1=intervals[0][0],e1=intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            int s2=intervals[i][0],e2=intervals[i][1];
            if(e1>=s2)
            return true;
            s1=s2;
            e1=e2;
        }
        return false;
    }
};