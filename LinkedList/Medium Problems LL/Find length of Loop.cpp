//Find length of Loop
/*  first detect the loop if there is no loop return 0 
    if there is loop then when you detect the loop starting
    counting node from there till the same node comes again 
*/

/*
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/
class Solution {
  public:
    int countNode(Node *slow){
      Node* temp=slow;
      int count=1;
      while(temp->next!=slow){
         temp=temp->next;
         count++;
      }
      return count;
    }
    int countNodesinLoop(Node *head) {
    Node* slow=head;
    Node* fast=head;
    while(fast and fast->next){
    slow=slow->next;
    fast=fast->next->next;
    if(fast==slow){
      return countNode(slow);
    }
    }
    return 0;
    }
};