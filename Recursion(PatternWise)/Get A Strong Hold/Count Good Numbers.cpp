//1922. Count Good Numbers
/*
1-digit number having 5 possibilities 0,2,4,6,8
2-digit number having 20 possibilities 5*4 where 5 numbers are even{0,2,4,6,8}, 4 numbers are prime numbers {2,3,5,7}
3-digit number having 100 possibilities  5*4*5 
4-digit number having 400 possibilities 5*4*5*4
like that, we are having 2 numbers 5 and 4 so power we have to find if n is even then we have to take equal no's of 5 and 4 if n is odd then we have to multiply one more 5 in ans 
and for finding power find power for half only multiply same ans with it.
*/
#define modulo 1000000007
class Solution {
public:
    long long power(long long x, long long n) {
    if (n == 0) return 1;

    long long half = power(x, n / 2);
    half = (half * half) % modulo;

    if (n % 2 == 1)
        half = (half * x) % modulo;

    return half;
}

    int countGoodNumbers(long long n) {
        long long num, num1, ans;

        if (n % 2 == 0) {
            num  = power(4, n / 2);
            num1 = power(5, n / 2);
            ans  = (num * num1) % modulo;
        } else {
            num  = power(4, n / 2);
            num1 = power(5, n / 2);
            ans  = (num * num1 * 5) % modulo;
        }
        return (int)ans;
    }
};

