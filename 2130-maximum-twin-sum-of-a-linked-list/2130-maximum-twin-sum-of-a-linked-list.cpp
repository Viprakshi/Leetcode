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
    ListNode* reverse(ListNode* head){
    ListNode* prev = NULL;
    ListNode* curr = head;

    while(curr){
        ListNode* nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }

    return prev;
}
    int pairSum(ListNode* head) {
        if(head->next->next==NULL) return head->val+head->next->val;
        int max_sum=0;
        ListNode *slow=head, *fast=head->next;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        } 
        ListNode* last_head=reverse(slow->next);
        slow->next=NULL;
        ListNode *left=head, *right=last_head;
        while(left && right){
            max_sum=max(max_sum, right->val+left->val);
            left=left->next;
            right=right->next;
        } 
        return max_sum;
    }
};