//61. Rotate List
/*If the list is empty, return head.
here first we are counting number of nodes in list and then we are taking modulo of total number of nodes with k
because 
If k = 8 and count = 5, rotating 8 times is the same as rotating 3 times (8 % 5 = 3).
now making list circular by connecting last node with head
now we will break the loop suppose we want to rotate 2 times and total nodes are 5 then 5-2=3  the loop will stop before 3 
and then we will point one another pointer named temp2 to its next node and we will break the loop from that node by putting its next address = nullptr
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head==nullptr){
          return head;
        } 
        int count= 1;
        ListNode* temp = head;
        while (temp->next) {
            count++;
            temp = temp->next;
        }
        k = k%count;
        temp->next = head;
        for (int i = 0; i < count - k; i++)
        {
            temp = temp->next;
        }
        ListNode* temp2 = temp->next;
        temp->next = nullptr;
        return temp2;
    }
};