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
    ListNode* find_middle(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode* merge(ListNode* left, ListNode* right){
        ListNode* head=NULL;
        ListNode* join=NULL;
        while(left && right){
            if(left->val<=right->val){
                if(head==NULL){
                    head=left;
                    join=left;
                    left=left->next;
                    
                }
                else{
                    join->next=left;
                    join=left;
                    left=left->next;
                }
            }
            else{
                if(head==NULL){
                    head=right;
                    join=right;
                    right=right->next;
                    
                }
                else{
                    join->next=right;
                    join=right;
                    right=right->next;
                }
            }
            

        }
        if(left) join->next=left;
            else join->next=right;
        return head;
    }
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* middle=find_middle(head);
        ListNode* left=head;
        ListNode* right=middle->next;
        middle->next=NULL;

        ListNode* leftside=sortList(left);
        ListNode* rightside=sortList(right);

        return merge(leftside, rightside);
        
    }
};