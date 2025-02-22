//234. Palindrome Linked List
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
/*
--> here we are reaching to the middle point with tortoise meathod for that we are declaring two pointers fast and slow and running while loop
--> declaring one temp1 pointer for pointing half of the list and declaring temp2 pointer for another half of the list 
--> declaring curr and next pointer for reversing the list 
--> point curr to the middle node and prev and next as null initially then reverse the remaining part of the list
--> declare temp2 pointer pointing that reveresed list and then compare temp1 and temp2's val till temp2 ends if you find any different value in between then return false otherwise return true.
 */

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* fast= head;
        ListNode* slow= head;
        ListNode* temp1=head;
        ListNode* temp2;
        ListNode* curr;
        ListNode* Next;

        while(fast and fast->next){
          fast = fast->next->next;
          slow = slow->next;
        }
        curr = slow;
        Next = nullptr;
        ListNode* prev=nullptr;
        while(curr){
            Next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=Next;   
        }
       temp2=prev;
       while(temp2){
        if(temp1->val != temp2->val){
           return false; 
        }
        temp1= temp1->next;
        temp2= temp2->next;
       }
    return true;
    }
};