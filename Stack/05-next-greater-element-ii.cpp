/*
Problem: Next Greater Element II
Platform: LeetCode
Link: https://leetcode.com/problems/next-greater-element-ii/

Approach:
Use a monotonic decreasing stack and traverse the array twice
to handle its circular nature. Pop elements smaller than or equal
to the current element. If the stack is non-empty, its top is the
next greater element. Otherwise, the answer remains -1.

Time: O(n)
Space: O(n)
*/

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        stack<int> st;
        vector<int> res(n,-1);
        for(int it=2*n-1;it>=0;it--){
            int i=it%n;
            while(!st.empty()&&st.top()<=nums[i])
            st.pop();
            if(!st.empty())
            res[i]=st.top();
            st.push(nums[i]);
        }
        return res;
    }
};