/*
Problem: Longest Substring with K Unique Characters
Platform: GeeksforGeeks
Link: https://www.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1

Approach:
Use a variable-size sliding window with a frequency map.
Expand the window by adding characters from the right.
When the window contains more than k unique characters, shrink it
from the left until it contains at most k unique characters.
Track the longest window containing exactly k unique characters.

Time: O(n)
Space: O(k)
*/

class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        unordered_map<char,int> mpp;
        int high=0,low=0,res=INT_MIN;
        for(high=0;high<s.size();high++){
            mpp[s[high]]++;
            while(mpp.size()>k){
                mpp[s[low]]--;
                if(mpp[s[low]]==0)
                mpp.erase(s[low]);
                low++;
            }
            if(mpp.size()==k)
            res=max(res,high-low+1);
        }
        return (res==INT_MIN)?-1:res;
    }
};