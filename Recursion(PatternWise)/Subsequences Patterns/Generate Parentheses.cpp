//22. Generate Parentheses
/*
 We use backtracking with open and close counters starting from n.
'(' is added only when open > 0.
')' is added only when close > open to maintain validity.
 This prevents invalid parentheses from being generated.
 When both open and close become 0, a valid string is formed and added to the answer.
*/
class Solution {
public:
    void f(string sub,int open, int close, vector<string> &ans){
        if(open==0 && close==0){
          ans.push_back(sub);
          return;
        }
        if(open>0){
          f(sub + '(', open-1,close, ans);
        }
        if(close > open){
          f(sub + ')', open,close-1, ans);
        }
    }
    vector<string> generateParenthesis(int n) {
    vector<string> ans;
    string sub;
    f(sub,n,n,ans);
    return ans;
    }
};


https://leetcode.com/problems/generate-parentheses/