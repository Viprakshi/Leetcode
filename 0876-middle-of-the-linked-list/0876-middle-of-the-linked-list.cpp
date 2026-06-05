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
    ListNode* middleNode(ListNode* head) {
        ListNode *single=head;
        ListNode *fast=head;
        while(fast!=nullptr && fast->next!=nullptr){
            single=single->next;
            fast=fast->next;
            if(fast!=nullptr) fast=fast->next;
        }
        return single;
    }
};