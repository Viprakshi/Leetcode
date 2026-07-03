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
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL) return true;
        ListNode *slow=head;
        ListNode *fast=head;
        while(fast && fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }

        ListNode *curr=slow->next;
        slow->next = NULL;  
        ListNode *prev=slow;
        while(curr){
            ListNode *nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        ListNode *last=prev;
        ListNode *first=head;
        while(last && first){
            if(last->val!=first->val) return false;
            last=last->next;
            first=first->next;
        }
        return true;
    }
};