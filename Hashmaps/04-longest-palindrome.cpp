/*
Problem: Longest Palindrome
Platform: LeetCode
Link: https://leetcode.com/problems/longest-palindrome/

Approach:
Count the frequency of each character using a hash map.
Add all even frequencies to the answer. For odd frequencies,
add all but one character. If any odd frequency exists, one
remaining character can be placed in the center of the palindrome.

Time: O(n)
Space: O(1) for a fixed character set
*/

class Solution {
public:
    int longestPalindrome(string s) {
        int ans=0;
        bool odd=false;
        unordered_map<char,int> f;
        for(char c:s)
        f[c]++;
        for(auto it:f){
            if(it.second%2==0)
            ans+=it.second;
            else
            odd=true;
        }
        if(odd==false)
        return ans;
        for(auto it:f){
            if(it.second%2!=0)
            ans+=it.second-1;
        }
        return ans+1;
    }
};