class Solution {
public:
int recursion(int i, vector<int>& nums, int target){
     if(target == 0) return 0;
    if(target < 0 || i >= nums.size()) return  INT_MIN;

    int include =  recursion(i+1,nums,target-nums[i]);
    if(include != INT_MIN){
      include = 1 + include;
    }
    int exclude = 0 + recursion(i+1,nums,target);
    return max(include,exclude);
}

int memoisation(int i, vector<int>& nums, int target,vector<vector<int>>&dp){
     if(target == 0) return 0;
    if(target < 0 || i >= nums.size()) return  INT_MIN;
    if(dp[i][target]!=-1) return dp[i][target];
    int include =  memoisation(i+1,nums,target-nums[i],dp);
    if(include != INT_MIN){
      include = 1 + include;
    }
    int exclude = 0 + memoisation(i+1,nums,target,dp);
    return dp[i][target] = max(include,exclude);
}
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        vector<vector<int>>dp(nums.size()+1,vector<int>(target+1,-1));
        int ans = memoisation(0,nums,target,dp);
        return (ans == INT_MIN) ?-1:ans;
    }
};