//Introduction to Doubly Linked List


/*
class Node{
public:
    Node* prev;
    int data;
    Node* next;

    Node()
    {
        prev = NULL;
        data = 0;
        next = NULL;
    }

    Node(int value)
    {
        prev = NULL;
        data = value;
        next = NULL;
    }
};*/
/*

first we are creating one node as head and storing the first element of array in that node
and we are creating temp for itrating through whole link list and we are taking another
pointer named previous which is initially pointing towards null and inside the loop which
is starting from second index of array and going till the array ends and creating node 
each time and inside temp->next store the new_node's value and in new_node's prev
store temp move prev and move temp and return head when loop ends 

*/

class Solution {
  public:
    Node* constructDLL(vector<int>& arr) {
      Node* head = new Node(arr[0]);
      Node* temp = head;
      Node* prev = nullptr;
       for(int i=1;i<arr.size();i++){
           Node* new_node = new Node(arr[i]); //creating node
           temp->next = new_node; 
           new_node->prev=temp;
           prev=temp;
           temp=new_node;
       }
       return head;
    }
};