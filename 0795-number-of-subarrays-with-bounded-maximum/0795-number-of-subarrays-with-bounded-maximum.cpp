class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int valid_index = -1;
        int invalid_index = -1;
        int ans = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] > right) invalid_index = i;
            if(nums[i] >= left) valid_index = i;
             ans+= max(0,valid_index - invalid_index);
        }
       
        return ans;
    }
};