class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        ListNode *temp1 = headA;
        ListNode *temp2 = headB;

        int count1 = 0;
        int count2 = 0;

       
        while(temp1 != NULL) {
            temp1 = temp1->next;
            count1++;
        }

     
        while(temp2 != NULL) {
            temp2 = temp2->next;
            count2++;
        }

        int diff = 0;

        ListNode *temp3 = headA;
        ListNode *temp4 = headB;

        if(count1 > count2) {

            diff = count1 - count2;

            for(int i = 0; i < diff; i++) {
                temp3 = temp3->next;
            }
        }

        else {

            diff = count2 - count1;

            for(int i = 0; i < diff; i++) {
                temp4 = temp4->next;
            }
        }

        
        while(temp3 != NULL && temp4 != NULL) {

            if(temp3 == temp4) {
                return temp3;
            }

            temp3 = temp3->next;
            temp4 = temp4->next;
        }

        return NULL;
    }
};