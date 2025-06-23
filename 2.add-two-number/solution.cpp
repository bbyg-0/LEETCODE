#include <iostream>

 //Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * result = new ListNode();
        ListNode * temp = result;
        int x = 0, y = 0;

        while(true){
            if(l1 != NULL) {result->val += (l1)->val; l1 = l1->next;}
            if(l2 != NULL) {result->val += (l2)->val; l2 = l2->next;}
            result->val += y;

            y = result->val/10;
            result->val %= 10;

            if(l1 == NULL && l2 == NULL && y == 0)  break;
            result->next = new ListNode(0, result);
            result = result->next;

            x = 0;
        }
        result->next = NULL;

        return temp;
    }
};

int main (void){
    ListNode * l1, * l2, * temp;

    l1 = new ListNode(9); temp = l1; 
    (l1)->next = new ListNode(9, l1); (l1) = (l1)->next;
    (l1)->next = new ListNode(9, l1); (l1) = (l1)->next;
    (l1)->next = new ListNode(9, NULL); l1 = temp;

    l2 = new ListNode(9); temp = l2; 
    (l2)->next = new ListNode(9, l2); (l2) = (l2)->next;
    (l2)->next = new ListNode(9, l2); (l2) = (l2)->next;
    (l2)->next = new ListNode(9, l2); (l2) = (l2)->next;
    (l2)->next = new ListNode(9, l2); (l2) = (l2)->next;
    (l2)->next = new ListNode(9, l2); (l2) = (l2)->next;
    (l2)->next = new ListNode(9, NULL); l2 = temp;



    Solution X;

    temp = X.addTwoNumbers(l1, l2);

    while(temp != NULL){
        std::cout << temp->val << std::endl;
        temp = temp->next;
    }

    return 0;
}
