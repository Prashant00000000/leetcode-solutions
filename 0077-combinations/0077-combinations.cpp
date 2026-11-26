class Solution {
public:
void recursion(int i,int n, int k, vector<int>&output, vector<vector<int>>&ans){
    if(output.size()==k){
        ans.push_back(output);
        return;
    }

    for(int j=i; j<=n; j++){
        output.push_back(j);
        recursion(j+1,n,k,output,ans);
        output.pop_back();
    }
}
    vector<vector<int>> combine(int n, int k) {
         vector<vector<int>> ans;
         vector<int>output;
         recursion(1,n,k,output,ans);
         return ans;
    }
};

