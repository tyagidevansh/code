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
    ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {
        if (head1 == NULL) return head2;
        if (head2 == NULL) return head1;

        ListNode* dummy = new ListNode();
        ListNode* head = dummy;

        while (head1 && head2) {
            if (head1->val < head2->val) {
                dummy->next = head1;
                head1 = head1->next;
            } else {
                dummy->next = head2;
                head2 = head2->next;
            }
            dummy = dummy->next;
        }

        if (head1) dummy -> next = head1;
        if (head2) dummy -> next = head2;

        return head->next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) {
            return NULL;
        }
        ListNode* head = lists[0];
        
        for (int i = 1; i < lists.size(); i++) {
            head = mergeTwoLists(head, lists[i]);
        }

        return head;
    }
};