//print longest common subsequence
/*
PROBLEM:
---------
Given two strings text1 and text2, find:
1) Length of the Longest Common Subsequence (LCS)
2) Print one possible LCS string

------------------------------------------------------------
IDEA:
-----
We use Dynamic Programming with TABULATION (bottom-up).

dp1[i][j] = length of LCS between:
            text1 starting from index i
            text2 starting from index j

That means:
- dp1[0][0] → LCS length of full strings
- dp table is filled from bottom-right to top-left

------------------------------------------------------------
DP TRANSITION:
--------------
If characters match:
    text1[i] == text2[j]
    → take that character
    → move diagonally
    dp1[i][j] = 1 + dp1[i+1][j+1]

If characters do NOT match:
    → skip one character
    → take the maximum of:
       - skipping from text1 (down)
       - skipping from text2 (right)
    dp1[i][j] = max(dp1[i+1][j], dp1[i][j+1])

------------------------------------------------------------
WHY TABLE SIZE IS (l1+1) x (l2+1):
----------------------------------
Extra row and column act as base case:
- When one string is exhausted, LCS = 0
- This avoids out-of-bounds checks

------------------------------------------------------------
RECONSTRUCTING THE LCS STRING:
-------------------------------
We start from dp1[0][0] and move forward.

Pointers:
    i → index in text1
    j → index in text2

While i < l1 and j < l2:
1) If text1[i] == text2[j]:
   - This character is part of LCS
   - Add it to result
   - Move diagonally → i++, j++

2) If characters don't match:
   - Compare dp values:
       dp1[i][j+1]  (move right)
       dp1[i+1][j]  (move down)
   - Move in the direction of the larger value
   - This ensures we stay on the optimal LCS path

------------------------------------------------------------
TIME & SPACE COMPLEXITY:
------------------------
Time Complexity:
    O(l1 * l2)

Space Complexity:
    O(l1 * l2)

------------------------------------------------------------
KEY TAKEAWAYS:
--------------
✔ DP is filled from end because dp[i] depends on dp[i+1]
✔ Matching chars → diagonal move
✔ Non-matching chars → move towards larger dp value
✔ dp1[0][0] gives LCS length
✔ Traversing dp table gives the actual LCS string

============================================================
*/

class Solution {
public:
 int tabulation(int i, int j, string& text1, string& text2, int l1, int l2,
                   vector<vector<int>> &dp1) {
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
    int longestCommonSubsequence(string text1, string text2) {
      int l1 = text1.size();
      int l2 = text2.size();
      string result;
      vector<vector<int>> dp1(l1 + 1, vector<int>(l2 + 1, 0));
      int ans=tabulation(0,0,text1,text2,l1,l2,dp1);
      for(int i=0;i<dp1.size();i++){
          for(int j=0;j<dp1[i].size();j++){
            cout<<dp1[i][j];
          }
      }
      int i=0;int j=0;
      while(i<l1 && j<l2){
       if(text1[i] == text2[j]){
        result.push_back(text1[i]);
        i++;
        j++;
       }
       else{
        if(dp1[i][j+1]>dp1[i+1][j]){
        j++;
       }
       else i++;
       }
    }
       cout<<result;
     return ans;
    }
};