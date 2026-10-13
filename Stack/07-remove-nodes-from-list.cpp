/*
Problem: Remove Nodes From Linked List
Platform: LeetCode
Link: https://leetcode.com/problems/remove-nodes-from-linked-list/

Approach:
Traverse the linked list and use a monotonic decreasing stack.
Pop elements smaller than the current node because they have a
greater value to their right. Push the current value onto the stack.
Rebuild the linked list from the remaining stack elements.

Time: O(n)
Space: O(n)
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
    ListNode* removeNodes(ListNode* head) {
        stack<int> st;
        ListNode* curr=head;
        while(curr!=nullptr){
            while(!st.empty()&&st.top()<curr->val)
            st.pop();
            st.push(curr->val);
            curr=curr->next;
        }
        ListNode dummy(0);
        while(!st.empty()){
            ListNode* node=new ListNode(st.top());
            node->next=dummy.next;
            dummy.next=node;
            st.pop();
        }
        return dummy.next;
    }
};