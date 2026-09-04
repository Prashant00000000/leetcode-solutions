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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL || head->next==NULL){
            return NULL ;
        }
        ListNode* temp = head;
        int count = 0;
        while(temp!=NULL){
            temp = temp->next;
            count++;
        }
        if(count==n){
            return head->next;
        }
        int res = count-n;
         ListNode* temp2 = head;
         while(res!=1){
            if(temp2->next==NULL) break;
            temp2 = temp2->next;
            res--;
         }
         ListNode* temp3 = temp2->next;
         temp2->next = temp2->next->next;
        
         delete temp3;
         return head;
    }
};