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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode *even=NULL;
        ListNode *join=NULL;
        ListNode *curr=head->next;
        ListNode *prev=head;
        while(curr){
            ListNode *next_odd=curr->next;
            if(even==NULL){
                even=curr;
                join=curr;
                curr->next=NULL;
            }
            else{
                join->next=curr;
                join=curr;
                curr->next=NULL;
            }
            prev->next=next_odd;
            if(next_odd){
                curr=next_odd->next;
                prev=next_odd;
            }
            else{
                prev->next=NULL;
                curr=NULL;
            }

        }
        prev->next=even;
        return head;
    }
};