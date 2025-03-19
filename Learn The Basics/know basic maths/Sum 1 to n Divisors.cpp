//Sum 1 to n Divisors
/*
try dividing number with 1 to n if number is divisible by it then add it in sum 
*/

// User function Template for C++
class Solution {
  public:
    int sumOfDivisors(int n){
    int sum=0;
    for(int i=1;i<=n;i++)
     for(int j=n;j>0;j--){
         if(i%j==0){
         sum+=j;
         }
        continue;
     }  
     return sum;
    }
};