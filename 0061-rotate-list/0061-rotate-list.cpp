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
        
        if(head==NULL || head->next==NULL) return head;
        int length=1;
        ListNode *temp=head;
        while(temp && temp->next!=NULL){
            length++;
            temp=temp->next;
        }
        k=k%length;
        if(k==0) return head;
        int to_reach=length-k;
        ListNode *end=head;
        while(to_reach>1 && end->next){
            end=end->next;
            to_reach--;
        }
        temp->next=head;
        head=end->next;
        end->next=NULL;
        return head;

    }
};