//Array to Linked List
/*Creating LinkedList from vector
firstly pushing one element in the node and creating one pointer
which is pointing to that new node and then one for loop for itreating through all 
the elements of vector and adding all of them by creating new node one by one and linking 
them with each other
*/
class Solution {
  public:
    Node* constructLL(vector<int>& arr) {
        Node* new_node = new Node(arr[0]);
        Node* temp=new_node;
        Node* head=new_node;
    for(int i=1;i<arr.size();i++){
    Node* new_node = new Node(arr[i]); 
    temp->next=new_node;
    temp=temp->next;
    }
    return head;
} 
};