//237. Delete Node in a Linked List
/*
as head is not given to us we will just take the value of given node and we will 
overwrite the value of it with next node's val so now both the node will have same values now we can unlinked
or make the next node unreachable 
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
     void deleteNode(ListNode* node) {
        node->val=node->next->val;
        node->next =node->next->next;    }
};