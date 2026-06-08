/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len_a=0, len_b=0;
        ListNode *temp=headA;
        while(temp!=nullptr){
            len_a++;
            temp=temp->next;
        }
        temp=headB;
        while(temp!=nullptr){
            len_b++;
            temp=temp->next;
        }
        ListNode *tempa=headA;
        ListNode *tempb=headB;
        if(len_a>len_b){
            while(len_a>len_b){
                tempa=tempa->next;
                len_a--;
            }
        }
        if(len_a<len_b){
            while(len_a<len_b){
                tempb=tempb->next;
                len_b--;
            }
        }
        while(tempa!=tempb){
            tempa=tempa->next;
            tempb=tempb->next;
        }
        return tempa;
    }
};