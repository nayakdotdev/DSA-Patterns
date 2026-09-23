/*
Problem: Linked List Cycle
Platform: LeetCode
Link: https://leetcode.com/problems/linked-list-cycle/

Approach:
Use two pointers, slow and fast, starting from the head.
Move slow one step at a time and fast two steps at a time.
If they meet, a cycle exists. If fast reaches the end, there is no cycle.

Time: O(n)
Space: O(1)
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *fast=head,*slow=head;
        while(fast!=nullptr&&fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)
            return true;
        }
        return false;
    }
};