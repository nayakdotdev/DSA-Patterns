/*
Problem: Maximum Number of Balloons
Platform: LeetCode
Link: https://leetcode.com/problems/maximum-number-of-balloons/

Approach:
Count the frequency of each character using a hash map.
Since "balloon" requires one b, one a, two l's, two o's, and one n,
divide the frequencies of l and o by 2. Return the minimum of these
counts to get the maximum number of balloons.

Time: O(n)
Space: O(1) for a fixed character set
*/

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int> f;
        for(char c:text)
        f[c]++;
        return min({f['b'],f['a'],f['l']/2,f['o']/2,f['n']});
    }
};