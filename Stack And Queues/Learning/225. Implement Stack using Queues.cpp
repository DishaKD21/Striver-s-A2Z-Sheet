//225. Implement Stack using Queues
// Using 2 queues
/*
here we are taking two queue q1 and q2 each time whenever we push new element we push it into q2 to maintain order and then we empty q1 by pushing all elements of q1 to q2 and then we swap all elements back again q2 to q1 
suppose we are pushing 1 in the q2
q1 = []                                 q1 = []                        q1 = [1]
q2 = [1]  push into q2  ----------->      q2 = [1]   ---------------->   swaped q2 = [] 
pushing 2
q1 = [1]                                 q1 = []     empty q1                   q1 = [2,1]
q2 = [2]  push into q2  ----------->      q2 = [2,1]   ---------------->   swaped q2 = [] 
pushing 3
q1 = [2,1]                                 q1 = []   empty q1                     q1 = [3,2,1]
q2 = [3]  push into q2  ----------->      q2 = [3,2,1]   ---------------->   swaped q2 = [] 

for poping its simple just pop the front element of q1
for top return the front element of q1
for empty return true or false by checking q1 is empty or not
*/
class MyStack {
public:
    queue<int> q1;
    queue<int> q2;
    MyStack() {}
    void push(int x) {
        q2.push(x);

        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }

        swap(q1, q2);
    }
    
    int pop() {
        int result = q1.front();
        q1.pop();

        return result;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return q1.empty();
    }
};

