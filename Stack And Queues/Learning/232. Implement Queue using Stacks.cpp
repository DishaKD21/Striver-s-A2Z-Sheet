//232. Implement Queue using Stacks
//using two Stacks
/*
Here we are taking two stacks while pushing we are checking if s2 is not empty then till its not empty push 
all the element of s2 to s1 if s2 is empty then push directly to s1
push 1
s1=[1]
s2=[]
push 2
s1=[1,2]
s2=[]
for poping push all the element of s1 to s2 and pop the element on the top return that element too 
s1=[]
s2=[2,1]   return the top which is 1 and pop it 
for peek element do the same return the top element of s2
for empty check both stack is empty or not 
*/
class MyQueue {
public:
   stack<int> s1;
   stack<int> s2;

    MyQueue() {}
   void push(int x) {
     if(!s2.empty()){
      while(!s2.empty()){
        s1.push(s2.top());
        s2.pop();
      }
     }
     s1.push(x);
    }
    
    int pop() {
       while(!s1.empty()) {
        s2.push(s1.top());
        s1.pop();
      } 
       int x= s2.top();
       s2.pop();
       return x;
    }
    
    int peek() {
      while(!s1.empty()) {
        s2.push(s1.top());
        s1.pop();
      }
      return s2.top();
    }
    
    bool empty() {
      return s1.empty() && s2.empty();  
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */