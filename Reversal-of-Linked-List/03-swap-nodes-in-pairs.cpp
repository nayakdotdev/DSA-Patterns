/*
Problem: Swap Nodes in Pairs
Platform: LeetCode
Link: https://leetcode.com/problems/swap-nodes-in-pairs/

Approach:
Reverse the linked list in groups of two nodes using a helper function.
Connect each reversed pair to the previous pair and continue with the
remaining nodes. If one node remains at the end, connect it unchanged.

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
    ListNode* swapPairs(ListNode* head) {
        if(head==nullptr)
        return head;
        ListNode* left=head;
        ListNode* res=nullptr;
        ListNode* right;
        ListNode* prevleft=nullptr;
        int size=2;
        while(true){
            right=left;
            for(int i=0;i<size-1;i++){
                if(right==nullptr)
                break;
                right=right->next;
            }
            if(right){
                ListNode* nextleft=right->next;
                reverse(left,size);
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