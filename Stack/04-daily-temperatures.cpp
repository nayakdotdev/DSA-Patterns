/*
Problem: Daily Temperatures
Platform: LeetCode
Link: https://leetcode.com/problems/daily-temperatures/

Approach:
Traverse the temperatures from right to left using a monotonic stack
of indices. Pop indices whose temperatures are less than or equal to
the current temperature. If the stack is non-empty, the top gives the
next warmer day's index. Store the difference between the indices.

Time: O(n)
Space: O(n)
*/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        stack<int> st;
        vector<int> res(n,0);
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&temperatures[st.top()]<=temperatures[i])
            st.pop();
            if(!st.empty())
            res[i]=st.top()-i;
            st.push(i);
        }
        return res;
    }
};