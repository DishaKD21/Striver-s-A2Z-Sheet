//2. Add Two Numbers
/*
here the approach is to simply add the numbers if carry comes than add it in next number
for that create a dummy node with value -1 for printing the whole list and one temp pointer to go through the list
taking one carry variable which is 0 initially 
running while loop for summing the element of l1 and l2 and in carry we are storing the first digit of the number 
creating new node with value last digit of the sum and linking new node with previous 
return the new list which we created.
*/

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* dummy = new ListNode(-1);
    ListNode* temp = dummy;
    int carry=0;
      while(l1 or l2 or carry){
        int x = carry + (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
        carry=x/10;
        ListNode* new_node = new ListNode(x%10); 
        temp->next= new_node;
        temp=temp->next;
        if(l1) l1=l1->next;
        if(l2) l2=l2->next;
        } 
    return dummy->next;
    }
};