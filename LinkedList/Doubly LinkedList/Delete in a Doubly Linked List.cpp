//Delete in a Doubly Linked List
/*
 here we are declaring one pointer temp which is pointing towards head and 
 there are 4 cases
 1)when head is null then we will return head
 2)when x is 1 which is first node then we will delete the first node 
 3)when x is somewhere in between in this case we will go to that place
 and then delete the node in this case node->next is not null
 4)in this case when node->next is null which means temp is pointing towards 
 the last node then delete the last node return the head 
*/
/* Structure of Node
class Node {
  public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
*/

class Solution {
  public:
    Node* deleteNode(Node* head, int x) {
        Node* temp = head;
       
        if(head==nullptr){
            return head;
        }
        int count=1;
        if(x==1){
            Node* p= temp;
            head = temp->next;
            if(head!=nullptr){
             head->prev = nullptr; 
            }
            delete p;
            return head;
        }
        while(count<x && temp->next!=nullptr){
            temp=temp->next;
            count++;
        }
        Node* p = temp;
        if(temp->next!=nullptr){
         temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        }
        else{
           temp->prev->next=nullptr; 
        }
        delete p;
        return head;
    }
};