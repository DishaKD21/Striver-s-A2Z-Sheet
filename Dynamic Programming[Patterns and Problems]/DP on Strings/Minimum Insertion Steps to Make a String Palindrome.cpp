//1312. Minimum Insertion Steps to Make a String Palindrome
/*
We find the Longest Palindromic Subsequence (LPS) by computing the LCS
between the string and its reverse. The minimum insertions required to
make the string a palindrome is the difference between the string length
and the LPS length, i.e., n − LPS.
*/
class Solution {
public:
  int tabulation(int i, int j, string& text1, string& text2, int l1, int l2,
                   vector<vector<int>> dp1) {
        for (int i = l1 - 1; i >= 0; i--) {
            for (int j = l2 - 1; j >= 0; j--) {
                if (text1[i] == text2[j]) {
                    dp1[i][j] = 1 + dp1[i + 1][j + 1];
                } else {
                    dp1[i][j] = max(dp1[i + 1][j], dp1[i][j + 1]);
                }
            }
        }
        return dp1[0][0];
    }
     int spaceOptimization(int i, int j, string& text1, string& text2, int l1,
                          int l2) {
        vector<int> next(l2 + 1, 0);
        vector<int> curr(l2 + 1, 0);
        for (int i = l1 - 1; i >= 0; i--) {
            for (int j = l2 - 1; j >= 0; j--) {
                if (text1[i] == text2[j]) {
                    curr[j] = 1 + next[j + 1];
                } else {
                    curr[j] = max(next[j], curr[j + 1]);
                }
            }
            next = curr;
        }
        return curr[0];
    }
    int minInsertions(string s) {
        int l1 = s.size();
        string s1 = s;
        vector<vector<int>> dp1(l1 + 1, vector<int>(l1 + 1, 0));
        reverse(s.begin(),s.end());
          
    return l1-tabulation(0,0,s,s1,l1,l1,dp1);
    }
};