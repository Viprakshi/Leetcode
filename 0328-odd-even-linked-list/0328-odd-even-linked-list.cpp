class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;

        ListNode *even=NULL;
        ListNode *join=NULL;

        ListNode *prev=head;
        ListNode *curr=head->next;

        while(curr){
            ListNode *nextOdd = curr->next;

            if(even==NULL){
                even=curr;
                join=curr;
            }
            else{
                join->next=curr;
                join=curr;
            }

            if(nextOdd){
                prev->next=nextOdd;
                prev=nextOdd;
                curr=nextOdd->next;
            }
            else{
                prev->next=NULL;
                curr=NULL;
            }

            join->next=NULL;
        }

        prev->next=even;
        return head;
    }
};