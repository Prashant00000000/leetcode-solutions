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
    bool isPalindrome(ListNode* head) {
        ListNode * slow = head;
        ListNode * fast = head;
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
       ListNode *curr = slow;
       ListNode *prev = NULL;
       ListNode *nextnode = NULL;
        while(curr!=NULL){
           nextnode = curr->next;
           curr->next = prev;
          prev = curr;
          curr = nextnode;
        }
        ListNode * p1 = head;
        ListNode * p2 = prev;
        while(p1!=NULL && p2!=NULL){
            if(p1->val == p2->val){
                p1 = p1->next;
                p2 = p2->next;
            }
            else{
                return false;
            }
        }
    return true;
    }
};