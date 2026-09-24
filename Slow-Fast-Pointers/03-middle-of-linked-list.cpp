/*
Problem: Middle of the Linked List
Platform: LeetCode
Link: https://leetcode.com/problems/middle-of-the-linked-list/

Approach:
Use two pointers, slow and fast, starting from the head.
Move slow one step and fast two steps at a time.
When fast reaches the end, slow will be at the middle of the linked list.

Time: O(n)
Space: O(1)
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *slow=head,*fast=head;
        while(fast!=nullptr&&fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
};