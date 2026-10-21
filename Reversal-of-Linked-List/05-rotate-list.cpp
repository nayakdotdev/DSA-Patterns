/*
Problem: Rotate List
Platform: LeetCode
Link: https://leetcode.com/problems/rotate-list/

Approach:
Find the length of the list and the last node. Reduce k using k % n.
Connect the last node to the head to form a circular list. Move to
the (n-k)th node, set its next pointer to nullptr, and return the
next node as the new head.

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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr)
        return head;
        int n=1;
        ListNode* last=head;
        while(last->next!=nullptr){
            n++;
            last=last->next;
        }
        k=k%n;
        if(k==0)
        return head;
        last->next=head;
        int pos=1;
        ListNode* p=head;
        while(p!=nullptr){
            if(pos==(n-k))
            break;
            pos++;
            p=p->next;
        }
        ListNode* res=p->next;
        p->next=nullptr;
        return res;
    }
};