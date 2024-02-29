class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head -> next || !head->next->next)
            return;

        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next && fast->next->next) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        ListNode* prev = NULL;
        ListNode* curr = slow -> next;
        slow->next = NULL;
        while(curr) {
            ListNode* nextNode = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = nextNode;
        }

        ListNode* first = head;
        ListNode* second = prev;
        while(second) {
            ListNode* temp1 = first -> next;
            ListNode* temp2 = second -> next;
            first -> next = second;
            second -> next = temp1;
            first = temp1;
            second = temp2;
        }
    }
};