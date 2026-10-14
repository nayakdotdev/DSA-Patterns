/*
Problem: First Unique Character in a String
Platform: LeetCode
Link: https://leetcode.com/problems/first-unique-character-in-a-string/description/

Approach:
Use a hash map to count the frequency of each character.
Traverse the string again and return the index of the first
character whose frequency is 1. If no such character exists,
return -1.

Time: O(n)
Space: O(1) for a fixed character set
*/

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> f;
        for(char c:s)
        f[c]++;
        for(int i=0;i<s.size();i++){
            if(f[s[i]]==1)
            return i;
        }
        return -1;
    }
};