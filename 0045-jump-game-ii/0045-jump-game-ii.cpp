class Solution {
public:
int recursion(int index, int jumps,vector<int>& nums){
    if(index>=nums.size()-1) {
        return jumps;
    }
    int mini_jumps = INT_MAX;
    for(int i=1; i<=nums[index]; i++){
        mini_jumps = min(mini_jumps,recursion(index+i,jumps+1,nums));
    }
    return mini_jumps;
}

int memoisation(int index,vector<int>& nums,vector<int>&dp){
    if(index>=nums.size()-1) {
        return 0;
    }
    if(dp[index]!=-1){
        return dp[index];
    }
    int mini_jumps = INT_MAX;
    for(int i=1; i<=nums[index]; i++){
    int ans = memoisation(index+i, nums, dp);

    if(ans != INT_MAX){
        mini_jumps = min(mini_jumps, 1 + ans);
    }
  }
    return dp[index]= mini_jumps;
}

    int jump(vector<int>& nums) {
        // return recursion(0,0,nums); // index , jumps
      vector<int>dp(nums.size(),-1);
        return memoisation(0,nums,dp);
    }
};