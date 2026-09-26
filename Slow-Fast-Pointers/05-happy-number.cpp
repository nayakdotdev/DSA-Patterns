/*
Problem: Happy Number
Platform: LeetCode
Link: https://leetcode.com/problems/happy-number/

Approach:
Use Floyd's slow and fast pointer algorithm to detect a cycle.
The slow pointer calculates the next number once, while the fast
pointer calculates it twice. If fast reaches 1, the number is happy.
If slow and fast meet at a value other than 1, a cycle exists and
the number is not happy.

Time: O(log n)
Space: O(1)
*/

class Solution {
public:
    int fun(int n){
        int s=0;
        while(n>0){
            int d=n%10;
            s+=d*d;
            n/=10;
        }
        return s;
    }
    bool isHappy(int n) {
        int s=n,f=n;
        while(f!=1){
            s=fun(s);
            f=fun(f);
            f=fun(f);
            if(s==f&&s!=1)
            return false;
        }
        return true;
    }
};