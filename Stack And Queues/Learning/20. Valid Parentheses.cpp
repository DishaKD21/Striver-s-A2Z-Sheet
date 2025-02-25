//20. Valid Parentheses
/*
solution is
--> first check if the string is starting with closing parentheses then return false
--> if that's not the case then when you see opening parantheses push it into the stack else 
check stack is empty then return false or if stack's top match with string's closing paranthese then pop that 
check at last if stack is not empty at last then return false 
*/
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
       if(s[0]=='}' or s[0]==']' or s[0]==')'){
        return false;
       }
       for(int i=0;i<s.size();i++){     
        if(s[i]=='{' or s[i]=='[' or s[i]=='(' )
       { st.push(s[i]);
       } 
       else
       {
          if (st.empty()) {
                    return false;
                }
        if(st.top() =='{' && s[i] =='}' || st.top()=='[' && s[i] ==']' || st.top() =='(' && s[i] ==')'){
            st.pop();
        }
        else{
           return false;
        }
       }
    }
    if(st.empty()){
        return true;
    }
    else{
        return false;
    }
    }
};