/*
Problem: Reverse Linked List II
Platform: LeetCode
Link: https://leetcode.com/problems/reverse-linked-list-ii/

Approach:
Move to the node at position left while keeping track of the
previous node. Reverse the sublist from left to right using three
pointers. Connect the reversed sublist to the remaining list and
update the previous node's next pointer if needed.

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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==nullptr || left==right)
        return head;
        ListNode* t=head;
        ListNode* before=nullptr;
        int pos=1;
        while(pos<left){
            before=t;
            t=t->next;
            pos++;
        }
        ListNode* curr=t;
        ListNode* prev=nullptr;
        int times=right-left+1;
        while(times--){
            ListNode* n=curr->next;
            curr->next=prev;
            prev=curr;
            curr=n;
        }
        t->next=curr;
        if(before!=nullptr){
            before->next=prev;
            return head;
        }
        return prev;
    }
};