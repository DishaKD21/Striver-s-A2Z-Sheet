//Generate all binary strings
/*
We generate binary strings by adding one character at a time.
If n == 0, the string is complete, so we store it.
Otherwise, we try both choices at each step:
add '0'
add '1'
ach recursive call gets its own copy of the string, so changes in one
call do not affect others.
*/

class Solution {
  public:
    void find(string sub,vector<string> &ans,int n){
      if(n==0){
          ans.push_back(sub);
          return;
      }
    find(sub + '0', ans, n - 1);
    find(sub + '1', ans, n - 1);
    }
    vector<string> binstr(int n){
      vector<string> ans;
      string sub;
      find(sub,ans,n);
      return ans;
    }
};

https://www.geeksforgeeks.org/problems/generate-all-binary-strings/1