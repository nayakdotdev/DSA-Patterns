/*
Problem: Valid Parentheses
Platform: LeetCode
Link: https://leetcode.com/problems/valid-parentheses/

Approach:
Use a stack to store opening brackets. For each closing bracket,
check whether the stack is non-empty and its top matches the
corresponding opening bracket. Return false for any mismatch.
The string is valid if the stack is empty at the end.

Time: O(n)
Space: O(n)
*/

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char c:s){
            if(c=='{'||c=='('||c=='[')
            st.push(c);
            else{
                if(st.empty())
                return false;
                if((c==')'&&st.top()=='(')||(c=='}'&&st.top()=='{')||(c==']'&&st.top()=='['))
                st.pop();
                else
                return false;
            }
        }
        return st.empty();
    }
};