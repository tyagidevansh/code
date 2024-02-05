class Solution {
    public:
        ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
            if (!list1) return list2;
            if (!list2) return list1;

            ListNode* dummy = new ListNode(-1);
            ListNode* tail = dummy;

            while (list1 && list2) {
                if (list1->val <= list2->val) {
                    tail->next = list1;
                    list1 = list1->next;
                } else {
                    tail->next = list2;
                    list2 = list2->next;
                }
                tail = tail->next;
            }

            if (list1) tail->next = list1;
            if (list2) tail->next = list2;

            return dummy->next;
        }
};