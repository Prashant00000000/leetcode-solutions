class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int leftsum = 0;
        int rightsum = 0;
        for(int i = 1; i<n; i++){
            rightsum+=nums[i];
        }
         int i = 0;
         while(i<n){
            if(leftsum != rightsum){
                leftsum+=nums[i];
                if(i+1<n){
                rightsum-=nums[i+1];
                i++;
                }
                else break;
            }
            else{
                return i;
            }
         }
         return -1;
    }
};