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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        int length = 0;

        while (temp != NULL) {
            temp = temp->next;
            length++;
        }

        ListNode* curr = head;
        ListNode* prevGroupLast = NULL;

        int count = 0;

        while (length - count >= k) {

            ListNode* groupFirst = curr;
            ListNode* prev = NULL;
            ListNode* nextnode = NULL;

            int m = k;

            while (m > 0) {
                nextnode = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nextnode;
                m--;
            }

            if (prevGroupLast == NULL) {
                head = prev;
            } else {
                prevGroupLast->next = prev;
            }

            groupFirst->next = curr;

            prevGroupLast = groupFirst;
            count += k;
        }

        return head;
    }
};