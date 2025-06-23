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
        ListNode * result = NULL;
        ListNode * temp = NULL;
        int x = 0, y = 0;

        while(l1 != NULL || l2 != NULL || y != 0){
            if(l1 != NULL) x += (l1)->val;
            if(l2 != NULL) x += (l2)->val;
            x += y;

            y = x/10;
            x %= 10;

            if(result == NULL){
                result = new ListNode(x);
                temp = result;
            }else{
                result->next = new ListNode(x, result);
                result = result->next;
            }

            x = 0;
            if(l1 != NULL) l1 = l1->next;
            if(l2 != NULL) l2 = l2->next;

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
