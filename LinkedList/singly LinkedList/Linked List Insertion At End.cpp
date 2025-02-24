//Linked List Insertion At End
/*
creating a new node and checking first if head is null or not if head is null 
then head = new_node else run a loop untill you reach at the end and at last
insert the node and return the head
*/
/*Structure of the linked list node is as
struct Node {
  int data;
  struct Node * next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

class Solution {
  public:
    Node *insertAtEnd(Node *head, int x) {
     Node* new_node = new Node(x);
     if(head==NULL)
   {
       head=new_node;
       return head;
   }
   Node* temp=head;
   while(temp->next!=NULL){
       temp=temp->next;
   }
    temp->next=new_node;
     return head;
    }
};
