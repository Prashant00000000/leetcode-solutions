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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        if(list1 == NULL && list2 == NULL) {
            return NULL;
        }

        if(list1 == NULL) {
            return list2;
        }

        if(list2 == NULL) {
            return list1;
        }

        ListNode* head1 = list1;
        ListNode* head2 = list2;

        ListNode* dummynode = new ListNode(-1);
        ListNode* firstnode = dummynode;

        while(head1 != NULL && head2 != NULL) {

            if(head1->val <= head2->val) {
                firstnode->next = head1;
                head1 = head1->next;
            }
            else {
                firstnode->next = head2;
                head2 = head2->next;
            }

            firstnode = firstnode->next;
        }

        while(head1 != NULL) {
            firstnode->next = head1;
            head1 = head1->next;
            firstnode = firstnode->next;
        }

        while(head2 != NULL) {
            firstnode->next = head2;
            head2 = head2->next;
            firstnode = firstnode->next;
        }

        return dummynode->next;
    }
};