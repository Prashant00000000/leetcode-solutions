class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxi_index = 0;
        for(int i=0; i<nums.size(); i++){
            if(i > maxi_index){
                return false;
            }
            maxi_index = max(maxi_index,i+nums[i]);
        }
        return true;
    }
};