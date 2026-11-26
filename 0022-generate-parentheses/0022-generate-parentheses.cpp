class Solution {
public:
bool isvalid(string&output){
    stack<char> st;
   for(auto ch: output){
     if(ch == '('){
        st.push(ch);
     }
     else{
        if(st.empty()) return false;
        char c = st.top();
        st.pop();
        if(c != '(') return false;
     }
   }
   return st.empty();
}
void recursion(int n,  string&output,vector<string>&ans){
    if(output.size() == 2*n){
    if(isvalid(output)){
        ans.push_back(output);
    }
    return;
   }

    output.push_back('(');
    recursion(n,output,ans);
    output.pop_back();

    output.push_back(')');
    recursion(n,output,ans);
    output.pop_back();
}
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string output  = "";
         recursion(n,output,ans);
         return ans;
    }
};