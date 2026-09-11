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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode * temp2 = head;
        int length = 0;
        while(temp2!=NULL){
            length++;
            temp2 = temp2->next;
        }
        if(k!=0 && length!=0){
        k = k% length;
        }
        if(head==NULL ){
            return NULL;
        }
        if(head->next==NULL|| k==0){
            return head;
        }
        ListNode* tail = head;

        while(tail->next!=NULL){
            tail = tail->next;
        }
        
        ListNode* temp = head;
            tail->next = temp;
           int m = length - k - 1;
         while(m != 0){
         temp = temp->next;
           m--;
            }

       
        head = temp->next;
        temp->next  = NULL;
        
        return head;
    }
};