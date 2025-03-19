//Armstrong Numbers
/*here take the last emelemt by taking reminder and take cube 
of that last element and add in sum and then devide the number 
with 10 then again run the loop untill no digit left and then 
check that sum with original number if its same then return 
true else false
*/
// User function Template for C++
class Solution {
  public:
    bool armstrongNumber(int n) {
       int x=n,rem,sum=0;
       while(x!=0){
         rem=x%10;
         sum+=rem*rem*rem;
         x=x/10;
       }
       if(sum==n){
           return true;
       }
       return false;
    }
};