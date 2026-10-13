/*
Problem: Remove All Adjacent Duplicates in String II
Platform: LeetCode
Link: https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/

Approach:
Use a stack of character-frequency pairs. If the current character
matches the stack's top, increment its count; otherwise, push it
with count 1. Remove the top when its count reaches k. Rebuild the
result using the remaining characters and their frequencies.

Time: O(n)
Space: O(n)
*/

class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> st;
        for(int c:s){
            if(!st.empty()&&st.top().first==c){
                st.top().second++;
                if(st.top().second==k)
                st.pop();
            }
            else
            st.push({c,1});
        }
        string res="";
        while(!st.empty()){
            pair<char,int> p=st.top();
            st.pop();
            res+=string(p.second,p.first);
        }
        reverse(begin(res),end(res));
        return res;
    }
};