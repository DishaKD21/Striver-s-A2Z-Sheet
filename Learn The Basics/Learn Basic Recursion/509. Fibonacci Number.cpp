//509. Fibonacci Number
/*
if n=0 and n=1 then return n
if n=4
sum =  f( 4 )==3
       |   |
     f(3) + f( 2 ) ==>2 + 1 =3
     |  |   |   |
  f(2)+f(1) f(1)+f(0)  
  |  |
f(1)+f(0)==>1
    
*/
class Solution {
public:
    int fib(int n) {
        if(n==0 || n==1){
           return n; 
        }
        else{
        
        return fib(n-1)+fib(n-2);

        }
    }
};