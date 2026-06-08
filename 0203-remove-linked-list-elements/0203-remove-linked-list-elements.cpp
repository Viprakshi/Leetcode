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
    ListNode* removeElements(ListNode* head, int val) {
        if(head==nullptr) return head;
        ListNode *temp=head;
        while(temp && temp->val==val){
            head=temp->next;
            temp=temp->next;
        }
        if(!temp) return temp;
        while(temp && temp->next){
            if(temp->next->val==val){
                if(temp->next->next) temp->next=temp->next->next;
                else temp->next=nullptr;
            }
            else
            temp=temp->next;
        }
        return head;
    }
};