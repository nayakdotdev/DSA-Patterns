/*
Problem: Ransom Note
Platform: LeetCode
Link: https://leetcode.com/problems/ransom-note/

Approach:
Use two hash maps to count character frequencies in ransomNote
and magazine. If any character appears more times in ransomNote
than in magazine, return false. Otherwise, return true.

Time: O(n + m)
Space: O(1) for a fixed character set
*/

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> r,m;
        for(char c:magazine)
        m[c]++;
        for(char c:ransomNote)
        r[c]++;
        for(char c:ransomNote){
            if(m[c]<r[c])
            return false;
        }
        return true;
    }
};