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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
 priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>,greater<pair<int, ListNode*>>> minheap;

        if(lists.size() == 0){
            return NULL;
        }

        for(int i = 0; i < lists.size(); i++){
            if(lists[i] != NULL){
                minheap.push({lists[i]->val, lists[i]});
            }
        }

        ListNode* dummynode = new ListNode(-1);
        ListNode* temp = dummynode;

        while(!minheap.empty()){

            auto pair = minheap.top();
            minheap.pop();

            temp->next = pair.second;
            temp = temp->next;

            if(pair.second->next != NULL){
                minheap.push({pair.second->next->val,pair.second->next});
            }
        }
        return dummynode->next;
    }
};