class Solution {
public:
void recursion(vector<int>& nums,vector<int>&output,vector<vector<int>>&ans){
    if(nums.empty()){
        ans.push_back(output);
        return;
    }
    for(int i=0; i<nums.size(); i++){
        if(i > 0 && nums[i] == nums[i-1]) {
       continue;
       }
        int ele = nums[i];
        output.push_back(nums[i]);
        vector<int>rem = nums;
        rem.erase(rem.begin()+i);
        recursion(rem,output,ans);
        output.pop_back();
    }
}
    vector<vector<int>> permuteUnique(vector<int>& nums) {
         vector<vector<int>>ans;
          sort(nums.begin(), nums.end());
         vector<int>output;
          recursion(nums,output,ans);
          return ans;
    }
};