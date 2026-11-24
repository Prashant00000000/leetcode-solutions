class Solution {
public:
void recursion(int i , vector<int>&candidates,vector<int>&temp, int n,vector<vector<int>>&ans,int count,int k ){
    if(count > k) return;

    if( count == k && n == 0){
        ans.push_back(temp);
        return;
    }
    if(i>=candidates.size()){
        return;
    }
    if(n < 0) return;
    temp.push_back(candidates[i]);
    recursion(i+1,candidates,temp,n-candidates[i],ans,count+1,k);
    temp.pop_back();
    while(i+1 < candidates.size() && candidates[i] == candidates[i+1]){
        i++;
    }

    recursion(i+1,candidates,temp,n,ans,count,k);
}
    vector<vector<int>> combinationSum3(int k, int n) {
         vector<vector<int>>ans;
         int count = 0;
         vector<int>temp;
         vector<int> candidates = {1,2,3,4,5,6,7,8,9};
         recursion(0,candidates,temp,n,ans,count,k);
         return ans;
    }
};