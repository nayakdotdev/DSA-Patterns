/*
Problem: Reverse Nodes in k-Group
Platform: LeetCode
Link: https://leetcode.com/problems/reverse-nodes-in-k-group/

Approach:
Process the linked list in groups of k nodes. Find the last node
of each group, save the next group's starting node, and reverse
the current group using a helper function. Connect each reversed
group to the previous group. If fewer than k nodes remain, keep
them in their original order.

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
    void reverse(ListNode* head,int times){
        ListNode* curr=head;
        ListNode* prev=nullptr;
        while(times--){
            ListNode* n=curr->next;
            curr->next=prev;
            prev=curr;
            curr=n;
        }
        return;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==nullptr)
        return head;
        ListNode* left=head;
        ListNode* res=nullptr;
        ListNode* right;
        ListNode* prevleft=nullptr;
        while(true){
            right=left;
            for(int i=0;i<k-1;i++){
                if(right==nullptr)
                break;
                right=right->next;
            }
            if(right){
                ListNode* nextleft=right->next;
                reverse(left,k);
                if(prevleft)
                prevleft->next=right;
                prevleft=left;
                if(res==nullptr)
                res=right;
                left=nextleft;
            }
            else{
                if(prevleft)
                prevleft->next=left;
                if(res==nullptr)
                res=left;
                break;
            }
        }
        return res;
    }
};