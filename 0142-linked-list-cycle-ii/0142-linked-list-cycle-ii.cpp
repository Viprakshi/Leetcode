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
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=nullptr && fast->next!=nullptr){

            slow=slow->next;
            fast=fast->next;
            //if(fast==nullptr) return false;
            fast=fast->next;
            if(slow==fast){
                break;
            }
        }
        slow=head;
        while(fast!=nullptr && fast->next!=nullptr){
            if(slow==fast){
                return slow;
            }
            slow=slow->next;
            fast=fast->next;
            //if(fast==nullptr) return false
            
        }
        return nullptr;
    }
};