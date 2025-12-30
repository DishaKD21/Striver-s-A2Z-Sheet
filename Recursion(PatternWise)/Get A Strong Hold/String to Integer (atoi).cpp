// 8. String to Integer (atoi)
/*first we are skipping all leading spaces then we are handling invalid and empty start 
 checking if there is negative sign then store it in variable as -1 so we can multiply the sign at the end
then add the char into ans string so after extracting all digits in string then we can convert that string into digit by multiplying into 10 each time and add it in that perticular char - '0'(asci val of 0 which is 48)
so we will get the digit.
at the end handle overflow by checking it is not being bigger than INT_MAX and lower than INT_MIN
return that number * sign so sign will be handled too.
*/

class Solution {
public:
    int myAtoi(string s) {
        int n = s.length();
        int i = 0;

        // 1. Skip leading spaces
        while (i < n && s[i] == ' ') i++;

        // 2. Handle empty or invalid start
        if (i == n) return 0;

        // 3. Handle sign
        int sign = 1;
        if (s[i] == '+' || s[i] == '-') {
            if (s[i] == '-') sign = -1;
            i++;
        }

        // 4. Extract digits 
        string ans;
        while (i < n && s[i] >= '0' && s[i] <= '9') {
            ans += s[i];
            i++;
        }

        // 5. Convert string to number 
        long num = 0;   // MUST initialize
        for (int j = 0; j < ans.length(); j++) {
            num = num * 10 + (ans[j] - '0');

            // 6. Overflow handling
            if (num * sign >= INT_MAX) return INT_MAX;
            if (num * sign <= INT_MIN) return INT_MIN;
        }

        return num * sign;
    }
};
