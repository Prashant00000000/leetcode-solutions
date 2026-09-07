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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* temp1 = l1;
        ListNode* temp2 = l2;

        int carry = 0;
        int result = 0;

        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        while(temp1 != NULL || temp2 != NULL || carry != 0) {

            int val1 = 0;
            int val2 = 0;

            if(temp1 != NULL)
                val1 = temp1->val;

            if(temp2 != NULL)
                val2 = temp2->val;

            result = val1 + val2 + carry;

            ListNode* newnode = new ListNode(result % 10);

            carry = result / 10;

            tail->next = newnode;
            tail = tail->next;

            if(temp1 != NULL)
                temp1 = temp1->next;

            if(temp2 != NULL)
                temp2 = temp2->next;
        }

        return dummy->next;
    }
};