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

        return end;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {

        if(!head || k == 1) return head;

        ListNode* prev_node = NULL;
        ListNode* start = head;
        ListNode* end = head;

        bool firstGroup = true;

        while(start) {

            int cnt = 1;

            while(cnt < k && end) {
                end = end->next;
                cnt++;
            }

            if(end == NULL) break;
            ListNode* next_node = end->next;
            reverseList(start, end);
            if(firstGroup) {
                head = end;          
                firstGroup = false;
            }
            else {
                prev_node->next = end;
            }

            prev_node = start;
            start = next_node;
            end = next_node;
        }

        return head;
    }
};