class Solution {
public:
    ListNode* reversal(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = NULL;

        while (temp != NULL) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    ListNode* getknode(ListNode* temp, int k) {
        k -= 1;
        while (temp != NULL && k > 0) {
            k--;
            temp = temp->next;
        }
        return temp;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevlast = NULL;

        while (temp != nullptr) {
            ListNode* kthnode = getknode(temp, k);
            if (kthnode == nullptr) {
                if (prevlast) {
                    prevlast -> next = temp;
                }
                break;
            }
            ListNode* nextnode = kthnode->next;
            kthnode->next = NULL;
            reversal(temp);

            if (temp == head) {
                head = kthnode;
            } else {
                prevlast->next = kthnode;
            }
            prevlast = temp;
            temp = nextnode;
        }
        return head;
    }
}