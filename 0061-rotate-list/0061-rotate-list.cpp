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
        if(head==NULL || !head->next || k==0) return head;
        int size=1;
        ListNode* temp=head;
        while(temp && temp->next){
            size++;
            temp=temp->next;
        }
        k=k%size;
        temp->next=head;
        for(int i=0;i<size-k;i++){
            temp=temp->next;
        }
        ListNode* new_head=temp->next;
        temp->next=0;

        return new_head;

    }
};