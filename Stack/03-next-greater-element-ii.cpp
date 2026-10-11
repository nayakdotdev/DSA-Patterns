/*
Problem: Next Greater Element II
Platform: LeetCode
Link: https://leetcode.com/problems/next-greater-element-ii/

Approach:
Traverse the array twice in reverse to simulate circular traversal.
Use a monotonic stack to store potential next greater elements.
Pop elements smaller than or equal to the current element.
The stack top gives the next greater element, or -1 if none exists.

Time: O(n)
Space: O(n)
*/

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        stack<int> st;
        vector<int> res(n,-1);
        for(int i=2*n-1;i>=0;i--){
            int idx=i%n;
            while(!st.empty()&&st.top()<=nums[idx])
            st.pop();
            if(st.empty())
            res[idx]=-1;
            else
            res[idx]=st.top();
            st.push(nums[idx]);
        }
        return res;
    }
};