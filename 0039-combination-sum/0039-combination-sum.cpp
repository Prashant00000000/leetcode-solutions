class Solution {
public:
void recursion(int i , vector<int>&candidates,vector<int>&temp, int target,vector<vector<int>>&ans ){
    if(target == 0){
        ans.push_back(temp);
        return;
    }
    if(i>=candidates.size()){
        return;
    }
    if(target < 0) return;
    temp.push_back(candidates[i]);
    recursion(i,candidates,temp,target-candidates[i],ans);
    temp.pop_back();

    recursion(i+1,candidates,temp,target,ans);
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
         vector<vector<int>>ans;
         vector<int>temp;
         recursion(0,candidates,temp,target,ans);
         return ans;
    }
};