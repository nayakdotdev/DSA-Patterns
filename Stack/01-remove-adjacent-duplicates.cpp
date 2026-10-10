/*
Problem: Remove All Adjacent Duplicates in String
Platform: LeetCode
Link: https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/

Approach:
Use a stack to process each character. If the stack is empty or its
top differs from the current character, push the character. Otherwise,
pop the top to remove the adjacent duplicate pair. Reverse the remaining
characters to obtain the result.

Time: O(n)
Space: O(n)
*/

class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        string res="";
        for(int i=0;i<s.size();i++){
            if(st.empty())
            st.push(s[i]);
            else if(st.top()!=s[i])
            st.push(s[i]);
            else if(st.top()==s[i])
            st.pop();
        }
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};