//Sort a linked list of 0s, 1s and 2s
/*
declaring 3 variable for counting each node having value 0,1 & 2 
then just going through whole list and just updating the value of the nodes 
and return the head
*/

/*

  Node is defined as
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
    // Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node* head) {
   
    int zero = 0, one = 0, two = 0;

    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == 0)
        {
            zero++;
        }
        else if (temp->data == 1)
        {
            one++;
        }
        else if (temp->data == 2)
        {
            two++;
        }

        temp = temp->next;
    }

    temp = head;

    while (temp != NULL)
    {
        if (zero != 0)
        {
            temp->data = 0;
            zero--;
        }
        else if (one != 0)
        {
            temp->data = 1;
            one--;
        }
        else if (two != 0)
        {
            temp->data = 2;
            two--;
        }
        temp = temp->next;
    }

    return head;
    }
};

/*
 Node* temp = head;
    Node* zeros = new Node(-1);
    Node* ones = new Node(-1);
    Node* twos = new Node(-1);
    Node* temp1= zeros;
    Node* temp2= ones;
    Node* temp3= twos;
    while(temp){
      if(temp->next->data==0){
        temp1->next=temp; 
        temp1=temp1->next;
      }
      else if(temp->next->data==1){
        temp2->next=temp; 
        temp2=temp2->next;
      }
      else if(temp->next->data==2){
         temp3->next=temp; 
         temp3=temp3->next; 
      }
      else{
          temp=temp->next;
      }
    }
    temp1->next = temp2->next ? temp2->next : temp3->next;
    temp2->next = temp3->next;
    temp3->next = nullptr;
    head = temp1->next;
    delete temp1;
    delete temp2;
    delete temp3;
    return head;
*/



 /*   Node* temp1=head;
        Node* temp=head;
        Node* temp2=head;
        while(temp2->next){
            temp2=temp2->next;
        }
        while(temp->next){
            if(temp->next->data==0){
               Node* p=temp->next;
               temp->next=temp->next->next;
               delete p;
               Node* new_node=new Node(0);
               new_node->next=temp1;
               temp1->next=new_node;
            }
             else if(temp->next->data==2){
               Node* p=temp->next;
               temp->next=temp->next->next;
               delete p;
               Node* new_node=new Node(2);
               temp2->next=new_node;
               temp2=temp2->next;
            }
            else{
                temp=temp->next;
            }
        }
        return head;
*/