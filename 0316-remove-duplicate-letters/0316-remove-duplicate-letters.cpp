class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.size();
        vector<bool>visited(26,false);
        string ans = "";
        vector<int>last_index(26);
        for(int i=0; i<n; i++){
            char ch = s[i];
            last_index[ch-'a'] = i;
        }
        for(int i=0; i<n; i++){
            char ch = s[i];
          int indx = ch - 'a';
            if(visited[indx] == true) continue;
            while(ans.size() > 0 && ans.back() > ch && last_index[ans.back()-'a'] > i){
               visited[ans.back()-'a'] = false;
                ans.pop_back();
            }
            ans.push_back(ch);
            visited[indx] = true;
        }
        return ans;
    }
};