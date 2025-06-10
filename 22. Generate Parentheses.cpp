/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 

Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:

Input: n = 1
Output: ["()"]
 

Constraints:

1 <= n <= 8
*/

class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(auto& c: s){
            if(c=='('){
                st.push(c);
            }
            else if(st.empty()) return false;
            else if(st.top() == '(' && c== ')') st.pop();
            else return false;
        }
        return (st.empty());
    }

    void solve(vector<string>& ans, string s,int n){
        if(s.size()==2*n) {
            if(isValid(s)) ans.push_back(s);
            return;
        }
        solve(ans,s+'(',n);
        solve(ans,s+')',n);
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string s = "";
        solve(ans,s,n);
        return ans;
    }
};
