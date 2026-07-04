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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            if(l1==NULL) return l2;
            if(l2==NULL) return l1;
            ListNode *temp1=l1;
            ListNode *temp2=l2;
            ListNode *track1=l1;
            ListNode *track2=l2;
            int carry=0;
            while(temp1 && temp2){
                int sum=temp1->val+temp2->val+carry;
                carry=sum/10;
                temp1->val=sum%10;
                track1=temp1;
                track2=temp2;
                temp1=temp1->next;
                temp2=temp2->next;
            }
            while(temp1){
                int x=temp1->val+carry;
                carry=x/10;
                temp1->val=x%10;
                track1=temp1;
                temp1=temp1->next;
            }

            if(temp2)
            track1->next=temp2;
            while(temp2){
                int x=temp2->val+carry;
                carry=x/10;
                temp2->val=x%10;
                track1=temp2;
                temp2=temp2->next;
            }

            if(!temp1 && !temp2 && carry!=0){
                track1->next = new ListNode();
                track1->next->val = carry;
            }
            return l1;
    }
};