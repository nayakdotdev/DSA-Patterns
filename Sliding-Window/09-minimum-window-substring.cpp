/*
Problem: Minimum Window Substring
Platform: LeetCode
Link: https://leetcode.com/problems/minimum-window-substring/

Approach:
Use a variable-size sliding window with frequency arrays for the
required and current characters. Expand the window until it contains
all characters of t with the required frequencies. Then shrink it
from the left while it remains valid, keeping track of the smallest
valid window.

Time: O(256 * n) ≈ O(n)
Space: O(1)
*/

class Solution {
public:
    bool check(vector<int> &n,vector<int> &h){
        for(int i=0;i<256;i++){
            if(h[i]<n[i])
            return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
        if(s.size()<t.size())
        return "";
        vector<int> have(256,0),need(256,0);
        for(char c:t)
        need[c]++;
        int high=0,low=0,res=INT_MAX,start=-1;
        for(high=0;high<s.size();high++){
            have[s[high]]++;
            while(check(need,have)){
                if(res>high-low+1){
                    res=high-low+1;
                    start=low;
                }
                have[s[low]]--;
                low++;
            }
        }
        return (res==INT_MAX)?"":s.substr(start,res);
    }
};