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

// while excluding, ignore the duplicate(Same) value and mmove to next value
while(i+1 < nums.size() && nums[i] == nums[i+1]){
    i++;
}
// exclude
recursion(i+1,nums,temp,ans);
}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>temp;
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        recursion(0,nums,temp,ans);
        return ans;
    }
};