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

    ListNode* reverseList(ListNode* start, ListNode* end) {

        ListNode* prev = end->next;
        ListNode* curr = start;

        while(prev != end) {
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }

        return end;   // new head of reversed group
    }

    ListNode* reverseKGroup(ListNode* head, int k) {

        if(!head || k == 1) return head;

        ListNode dummy(0);
        dummy.next = head;

        ListNode* prev_node = &dummy;
        ListNode* start = head;
        ListNode* end = head;

        while(start) {

            int cnt = 1;

            while(cnt < k && end) {
                end = end->next;
                cnt++;
            }

            if(end == NULL) break;

            ListNode* next_node = end->next;

            reverseList(start, end);

            prev_node->next = end;

            prev_node = start;
            start = next_node;
            end = next_node;
        }

        return dummy.next;
    }
};