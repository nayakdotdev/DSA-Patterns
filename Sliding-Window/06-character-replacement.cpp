/*
Problem: Longest Repeating Character Replacement
Platform: LeetCode
Link: https://leetcode.com/problems/longest-repeating-character-replacement/

Approach:
Use a variable-size sliding window with a frequency array.
The number of replacements needed is the window size minus the
frequency of the most frequent character. If this exceeds k,
shrink the window from the left. Track the maximum valid window length.

Time: O(256 * n) ≈ O(n)
Space: O(1)
*/

class Solution {
public:
    int find(vector<int>& a){
        int mx=INT_MIN;
        for(int i=0;i<a.size();i++)
        mx=max(mx,a[i]);
        return mx;
    }
    int characterReplacement(string s, int k) {
        int low=0,high=0,res=INT_MIN;
        vector<int> f(256,0);
        for(high=0;high<s.size();high++){
            f[s[high]]++;
            int diff=(high-low+1)-(find(f));
            while(diff>k){
                f[s[low]]--;
                low++;
                diff=(high-low+1)-(find(f));
            }
            res=max(res,high-low+1);
        }
        return res;
    }
};