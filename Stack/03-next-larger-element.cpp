/*
Problem: Next Larger Element
Platform: GeeksforGeeks
Link: https://www.geeksforgeeks.org/problems/next-larger-element-1587115620/1

Approach:
Traverse the array from right to left using a monotonic decreasing
stack. Pop elements smaller than or equal to the current element.
If the stack is non-empty, its top is the next greater element.
Otherwise, the answer remains -1.

Time: O(n)
Space: O(n)
*/

class Solution {
  public:
    vector<int> nextLargerElement(vector<int>& arr) {
        int n=arr.size();
        stack<int> st;
        vector<int> res(n,-1);
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&st.top()<=arr[i])
            st.pop();
            if(!st.empty())
            res[i]=st.top();
            st.push(arr[i]);
        }
        return res;
    }
};