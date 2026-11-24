class Solution {
public:
void recursion(int i,vector<int>& nums,vector<int>&temp,vector<vector<int>>&ans){
  if(i==nums.size()){
    ans.push_back(temp);
    return;
  }
  // include
  temp.push_back(nums[i]);
  recursion(i+1,nums,temp,ans);
  temp.pop_back();

// exclude
recursion(i+1,nums,temp,ans);
}
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>temp;
        vector<vector<int>>ans;
        recursion(0,nums,temp,ans);
        return ans;
    }
};