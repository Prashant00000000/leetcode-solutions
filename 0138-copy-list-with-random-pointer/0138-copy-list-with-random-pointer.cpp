/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {

public:

    Node* copyRandomList(Node* head) {

        // step-1-> Insert the nodes in between
        Node* temp = head;

         Node* copynode = NULL;

        while(temp!=NULL){

             copynode = new Node(temp->val);

            copynode->next = temp->next;

            temp->next = copynode;

            temp = temp->next->next;
        }

        //step-2-> Connect Random pointers

        temp = head;

        while(temp!=NULL){

            copynode = temp->next;

            if(temp->random!=NULL){
                copynode->random = temp->random->next;
            }
            else{
                copynode->random = NULL;
            }

            temp = temp->next->next;
        }

        // step-3-> connecting the next pointers

         Node* dummynode = new Node(-1);

         Node* res = dummynode;

         temp = head;

         while(temp!=NULL){

            res->next = temp->next;

            temp->next = temp->next->next;

            res = res->next;

            temp = temp->next;
         }

  return dummynode->next;

    }

};