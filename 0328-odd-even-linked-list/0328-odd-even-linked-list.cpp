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
    ListNode* oddEvenList(ListNode* head) {
          if(head == NULL) return head;
     ListNode* odd = head;
     vector<int>arr;
     while(odd!=NULL){
        arr.push_back(odd->val);
        if(odd->next==NULL) break;
        odd = odd->next->next;
     }
     ListNode* even = head->next;
     while(even!=NULL){
        arr.push_back(even->val);
        if(even->next==NULL) break;
        even = even->next->next;
     }
     ListNode* temp3  = head;
     for(int i=0; i<arr.size() && temp3!=NULL; i++){
        temp3->val = arr[i];
        temp3= temp3->next;
     }
     return head;
    }
};