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
    ListNode* mergetwolist(ListNode* head, ListNode* second) {

        if (head == NULL) return second;
        if (second == NULL) return head;

        ListNode* ans = NULL;

        if (head->val < second->val) {
            ans = head;
            ans->next = mergetwolist(head->next, second);
        }
        else {
            ans = second;
            ans->next = mergetwolist(head, second->next);
        }

        return ans;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {

        if (lists.size() == 0) return NULL;

        ListNode* head = lists[0];

        for (int i = 1; i < lists.size(); i++) {
            head = mergetwolist(head, lists[i]);
        }

        return head;
    }
};