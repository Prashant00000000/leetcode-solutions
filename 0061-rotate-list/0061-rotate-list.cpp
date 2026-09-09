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
        ListNode* temp = head;
        
        vector<int>ans;

        if(head == NULL || head->next == NULL) return head;

        while(temp!=NULL){
            ans.push_back(temp->val); 
            temp = temp->next;
        }
        int n = ans.size();

        k = k%n;

        // store last k elements
        vector<int> temp2(k);
        for (int i = 0; i < k; i++) {
            temp2[i] = ans[n - k + i];
        }
         //  shift elements to the right
        for (int i = n - 1; i >= k; i--) {
            ans[i] = ans[i - k];
        }
        // put temp elements as begniing
        for(int i=0; i<k; i++){
            ans[i] = temp2[i];
        }
        int i =  0;
         ListNode* temp4 = head;
        while(temp4!=NULL && i<n){
            temp4->val = ans[i];
            i++; 
            temp4 = temp4->next;
        }
        return head;
    }
};