class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
       long leftsum = 0;
        long rightsum = 0;
        int count = 0;
        for(int i=0; i<n; i++){
            rightsum+=nums[i];
        }
        int i = 0;
        while(i<n-1){
                leftsum+=nums[i];
                rightsum-=nums[i];
                 i++;
                 if(leftsum >=rightsum){
                count++;
              
            }
        }
        return count;
    }
};