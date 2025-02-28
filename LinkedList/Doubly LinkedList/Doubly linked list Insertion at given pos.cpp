//Doubly linked list Insertion at given position
/*
here we are declaring two pointers one pointer named temp for traversing 
and one named prev for keeping track of prev here indexing starts from 0 in list
so we will run a loop where we will stop at pos and we will insert after pos 
here suppose we want to insert 6 at pos 2 and list is 2<->4<->5 
Step 1: Start
count = 0
temp is at node with value 2 (head)
Step 2: First Loop Iteration
count = 0, which is < pos (2), so enter loop.
Move temp = temp->next (temp is now at node 4)
count = 1
Step 3: Second Loop Iteration
count = 1, which is < pos (2), so enter loop.
Move temp = temp->next (temp is now at node 5)
count = 2
Step 4: Third Check
count = 2, which is NOT < pos (2), so the loop stops.
now as we have reached to pos now we can insert node after pos
make sure to keep in mind the prev pointer also 
*/
/* a Node of the doubly linked list
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  Node(int x) { data = x; next = prev = NULL; }
}; */

class Solution {
  public:
    Node *addNode(Node *head, int pos, int data) {
      Node* new_node = new Node(data);
      int count=0;
      Node* temp = head;
      Node* prev = head;
      while(count<pos && temp->next != nullptr){
          temp= temp->next;
          count++;
      }
      new_node->next = temp->next;
      if (temp->next != nullptr) {
      temp->next->prev = new_node;
      }
      temp->next = new_node;
      new_node->prev = temp;
     return head; 
    }
};