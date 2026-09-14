/*
Problem: Count Triplets with Sum Smaller than X
Platform: GeeksforGeeks
Link: https://www.geeksforgeeks.org/problems/count-triplets-with-sum-smaller-than-x5549/1

Approach:
Sort the array and fix one element at a time.
Use two pointers to find pairs whose sum with the fixed element
is smaller than the given value. If the current sum is smaller,
all elements between the left and right pointers form valid triplets.

Time: O(n^2)
Space: O(1) excluding the sorting space
*/

class Solution {
  public:
    int countTriplets(int sum, vector<int>& arr) {
        sort(begin(arr),end(arr));
        int ans=0;
        for(int i=0;i<arr.size()-2;i++){
            int l=i+1,r=arr.size()-1;
            while(l<r){
                int s=arr[i]+arr[l]+arr[r];
                if(s<sum){
                    ans+=r-l;
                    l++;
                }
                else
                r--;
            }
        }
        return ans;
    }
};