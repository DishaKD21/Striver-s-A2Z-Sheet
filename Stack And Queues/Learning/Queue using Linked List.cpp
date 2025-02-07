//Queue using Linked List

/* Structure of a node in Queue
struct QueueNode
{
    int data;
    QueueNode *next;
    QueueNode(int a)
    {
        data = a;
        next = NULL;
    }
};
And structure of MyQueue
struct MyQueue {
    QueueNode *front;
    QueueNode *rear;
    void push(int);
    int pop();
    MyQueue() {front = rear = NULL;}
}; */

/*
while pushing we are checking if the node is created in heap or not 
if not the list is full else check for if the front is at null then we 
came to know that the element we are inserting is first one so point rear 
and front to that newly inserted node else we are just increasing the rear pointer 

while poping first check if front is at null then queue is empty sso retrun -1 
else save that node's value somewhere increase the front pointer and delete that 
node nd return the value
*/

//Function to push an element into the queue.
void MyQueue:: push(int x)
{   QueueNode *new_node= new QueueNode(x);
        if(front==nullptr){
            front=rear=new_node;
        }
        else{
            rear->next=new_node;
            rear=new_node;
        }
    
}
//Function to pop front element from the queue.
int MyQueue :: pop()
{
    int x=-1;
    QueueNode* p;
    if(front==nullptr){
        return -1;
    }
    else{
        p=front;
        x=front->data;
        front=front->next;
        delete p;
    }
    return x;
}

