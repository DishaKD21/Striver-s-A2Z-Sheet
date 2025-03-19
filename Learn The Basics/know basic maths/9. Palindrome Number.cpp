//9. Palindrome Number
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
then check that reversed number with original one
*/

class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }
        int num = x;
        long sum = 0;
        while(num != 0){
            int a = num%10;
            num /= 10;
            sum = (sum*10)+a;
        }
        if(sum == x){
            return true;
        }
        return false;
    }
};