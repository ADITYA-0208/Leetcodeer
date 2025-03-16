typedef ListNode node;
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        node *dummy1 = new node(-1), *dummy2 = new node(-1);
        node *temp1 = dummy1, *temp2 = dummy2, *temp = head;

        while(temp){
            if(temp->val<x){ 
                dummy1->next=temp;
                dummy1=dummy1->next;
            } 
            else{ 
                dummy2->next=temp;
                dummy2=dummy2->next;
            }
            temp = temp->next;
        }

        dummy2->next = nullptr;
        dummy1->next = temp2->next;
        return temp1->next; 
    }
};
