class Solution {
public:
void recursion(int start , vector<int>&temp, vector<vector<int>>&ans,int k,int n){
      if (temp.size() == k) {
        ans.push_back(temp);
        return;
    }
   for (int i = start; i <= n; i++) {
    temp.push_back(i);   
    recursion(i + 1, temp,ans,k,n);   
    temp.pop_back(); 
}
}
    vector<vector<int>> combine(int n, int k) {
        vector<int>temp;
        vector<vector<int>>ans;
      recursion(1,temp,ans,k,n);
      return ans;
    }
};