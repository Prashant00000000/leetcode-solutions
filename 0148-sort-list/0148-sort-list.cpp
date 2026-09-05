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

    // Find middle
    ListNode* findmiddle(ListNode* head) {
        ListNode* fast = head->next;
        ListNode* slow = head;

        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    // Merge two sorted linked lists
    ListNode* merge(ListNode* left, ListNode* right) {

        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        while(left != NULL && right != NULL) {

            if(left->val <= right->val) {
                temp->next = left;
                left = left->next;
            }
            else {
                temp->next = right;
                right = right->next;
            }

            temp = temp->next;
        }

        // Remaining nodes
        if(left != NULL) {
            temp->next = left;
        }
        else {
            temp->next = right;
        }

        ListNode* ans = dummy->next;
        delete dummy;

        return ans;
    }

    // Merge Sort
    ListNode* mergesort(ListNode* head) {

        // Base case
        if(head == NULL || head->next == NULL) {
            return head;
        }

        // Find middle
        ListNode* middle = findmiddle(head);

        // Divide into two lists
        ListNode* lefthead = head;
        ListNode* righthead = middle->next;

        middle->next = NULL;

        // Sort both halves
        lefthead = mergesort(lefthead);
        righthead = mergesort(righthead);

        // Merge sorted halves
        return merge(lefthead, righthead);
    }

    ListNode* sortList(ListNode* head) {

        return mergesort(head);
    }
};