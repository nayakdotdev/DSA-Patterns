/*
Problem: Longest Substring Without Repeating Characters
Platform: LeetCode
Link: https://leetcode.com/problems/longest-substring-without-repeating-characters/

Approach:
Use a variable-size sliding window with a frequency map.
Expand the window by adding characters from the right.
If the number of unique characters becomes smaller than the window
length, a duplicate exists, so shrink the window from the left until
all characters are unique. Track the maximum valid window length.

Time: O(n)
Space: O(k), where k is the number of distinct characters
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;
        int low=0,high=0,res=0;
        for(high=0;high<s.size();high++){
            mp[s[high]]++;
            int k=high-low+1;
            while(mp.size()<k){
                mp[s[low]]--;
                if(mp[s[low]]==0)
                mp.erase(s[low]);
                low++;
                k=high-low+1;
            }
            res=max(res,high-low+1);
        }
        return res;
    }
};