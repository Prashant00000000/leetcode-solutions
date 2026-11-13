class Solution {
public:

    vector<string> ans;

    bool isValid(string s) {
        stack<char> st;

        for(auto c : s) {
            if(c == '(') {
                st.push(c);
            }
            else {
                if(st.empty()) return false;

                char ch = st.top();
                st.pop();

                if(ch != '(') return false;
            }
        }

        return st.empty();
    }

    void recursion(string &s, int n) {

        if(s.size() == 2*n) {
            if(isValid(s)) {
                ans.push_back(s);
            }
            return;
        }

        s.push_back('(');
        recursion(s,n);
        s.pop_back();

        s.push_back(')');
        recursion(s,n);
        s.pop_back();
    }

    vector<string> generateParenthesis(int n) {
        string s = "";
        recursion(s,n);
        return ans;
    }
};