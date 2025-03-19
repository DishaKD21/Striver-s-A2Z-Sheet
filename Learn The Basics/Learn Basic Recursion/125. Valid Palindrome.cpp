//125. Valid Palindrome
/*
making a function for checking char is alphabet or numeric value converting those 
in lower char and storing it in string variable and if its not alphanumeric 
then continue then we are comparing last and first value of string till lower
index is lower than higher index if any value of string is not same then return 
false else true
*/
class Solution {
public:
    bool isPalindrome(string s) {
        string ans;
        for (int i = 0; i < s.length(); i++) {
            if (isAlphanumeric(s[i])) {
                ans += tolower(s[i]);
            } else {
                continue;
            }
        }
        int l = 0, r = ans.length()-1;
        while (l < r) {
            if (ans[l] != ans[r]) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
    bool isAlphanumeric(char x) {

        if (x >= 'a' && x <= 'z' or x >= 'A' && x <= 'Z' or
            x>='0' && x<= '9') {
            return true;
        }
        return false;
    }
};