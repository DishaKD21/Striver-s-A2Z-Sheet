//7. Reverse Integer
/*
here we are running loop till given number is != 0 each time finding reminder for 
getting last number everytime adding it into the sum also multiplying sum with 10 
and at end we are dividing number with 10 each time 
suppose number is 123 then in first iteration 
num=123
rem=3,sum = sum*10 +rem -->0*10+3 ===>3will be stored 
num=123/10-->12
next iteration
num=12
rem=2 ,sum=3*10+2==>32
num=12/10-->1
next iteration
num=1
rem=1 ,sum= 32*10 +1 ==> 321 will get stored
num=1/10==>0
loop terminated
*/
class Solution {
public:
    int reverse(int x) {
     long sum=0;
      while(x!=0){
        int rem=x%10;
        sum = sum*10 +rem;
        x = x/10;
      }
      if(sum>INT_MAX || sum<INT_MIN){
        return 0;
      }
    
    return (int)sum;
    }
};