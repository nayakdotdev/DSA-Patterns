/*
Problem: Linked List Cycle II
Platform: LeetCode
Link: https://leetcode.com/problems/linked-list-cycle-ii/

Approach:
Use slow and fast pointers to detect a cycle. Once they meet,
reset the slow pointer to the head and move both pointers one step
at a time. Their next meeting point is the start of the cycle.

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
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow=head,*fast=head;
        while(fast!=nullptr&&fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                slow=head;
                while(slow!=fast){
                    slow=slow->next;
                    fast=fast->next;
                }
                return slow;
            }
        }
        return nullptr;
    }
};