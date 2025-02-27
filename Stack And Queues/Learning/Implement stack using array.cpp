//Implement stack using array
/*
here we are declaring two things one is array and one is top variable to keep 
track of the recent element which got added when pushing increasing top and storing 
the new element at that place and when poping checking if top is -1 then return -1 
otherwise return top value and decrease the top
*/
class MyStack {
    private int[] arr;
    private int top;

    public MyStack() {
        arr = new int[1000];
        top = -1;
    }
    public void push(int x) {
      
       arr[++top]=x;
    }
    public int pop() {
        if(top==-1){
            return -1;
        }
        return arr[top--];
    }
}