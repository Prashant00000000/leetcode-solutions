class Solution {
public:
  vector<vector<int>>ans;
void recursion(vector<int>&nums,int i,vector<int>&temp){
if(i==nums.size()){
   ans.push_back(temp);
   return;
}
// include
temp.push_back(nums[i]);
recursion(nums,i+1,temp);
temp.pop_back();

//exclude
recursion(nums,i+1,temp);


}
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>temp;
        recursion(nums,0,temp);
        return ans;
    }
};