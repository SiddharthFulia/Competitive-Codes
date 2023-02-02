//https://leetcode.com/problems/generate-parentheses/submissions/889828916/
class Solution {
public:
vector<string> valid;
void generate(string &s,int open,int close){
  if(open==0 && close==0){
    valid.push_back(s);
    return;
  }
  if(open>0){
    s.push_back('(');
    generate(s,open-1,close);
    s.pop_back();//backtrack or pop the last letter to maintain the state of string in current function
  }
  if(close>0){
    if(open<close){
      s.push_back(')');
      generate(s,open,close-1);
      s.pop_back();
    }
  }
}
    vector<string> generateParenthesis(int n) {
        string s;
        generate(s,n,n);
        return valid;
    }
};