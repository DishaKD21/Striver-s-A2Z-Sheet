//50. Pow(x, n)
/*
caling function each time by reducing 1 power using recursion will give stack overflow because so many function call will be made so we are deviding power first then numlyplying the same result with itself to get ans so that we can reduce the number of fucntion calls in half.
*/
class Solution {
public:
  double power(double x, int n) {
    if(n==0) return 1; 
    if(n<0)
    {
    return 1/x*myPow(x,n+1);
    }
    return x*myPow(x,n-1);
    }

    double myPow(double x, int n) {
    double num;
    if(n%2==0){
    num = power(x,n/2);
    num = num*num;
    }
    else{
     if(n>0){
        num=power(x,n/2);
        num = num* num * x;
     }
     else {
        num = power(x,n/2);
        num = num*num*1/x;
     }
    }
    return num;
    }
};