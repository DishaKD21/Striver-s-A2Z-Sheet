//1903. Largest Odd Number in String
/*check for last digit in number if its odd then return that digit 
run a for loop inside the string and check odd number put it in max take the max odd number save it in variable and then see if max having value -1 then return empty substring otherwise return the number as string which is odd and biggest */

class Solution {
public:
    string largestOddNumber(string num) {
        int maxi = -1;

        // Check if last digit is odd
        if ((num.back() - '0') % 2 != 0) {
            return num;
        } 
        else {
            for (int i = 0; i < num.length(); i++) {
                if ((num[i] - '0') % 2 != 0) {
                    maxi = max(i, maxi);
                }
            }
        }

        if (maxi == -1) {
            return "";
        }

        return num.substr(0, maxi + 1);
    }
};
