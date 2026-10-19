/*
Problem: Reverse Linked List
Platform: LeetCode
Link: https://leetcode.com/problems/reverse-linked-list/

Approach:
Use three pointers: curr, prev, and f. Store the next node in f,
reverse the current node's link to prev, then move prev and curr
one step forward. Repeat until curr becomes nullptr.

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
    ListNode* reverseList(ListNode* head) {
        ListNode* curr=head;
        ListNode* prev=nullptr;
        while(curr!=nullptr){
            ListNode* f=curr->next;
            curr->next=prev;
            prev=curr;
            curr=f;
        }
        return prev;
    }
};