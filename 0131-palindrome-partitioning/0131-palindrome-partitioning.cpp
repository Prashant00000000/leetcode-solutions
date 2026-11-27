class Solution {
public:
bool isPalindrome(string &s){
    int i=0;
    int j=s.size()-1;
    while(i<j){
        if(s[i]!=s[j]){
            return false;
        }
        else {
            i++;
            j--;
        }
    }
    return true;
}
void recursion(int i,vector<string>&output,string&s, vector<vector<string>>&ans){
    // base case
    if(i == s.size()){
        ans.push_back(output);
        return;
    }
  for(int j=i; j<s.size(); j++){
    string temp = s.substr(i,j-i+1);
    if(isPalindrome(temp)){
        output.push_back(temp);

    recursion(j+1,output,s,ans);
    output.pop_back();
    }
  }

}

    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>output;
         recursion(0,output,s,ans); 
         return ans;
    }
};