class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int pivot_index = -1;
        for(int i=n-1; i>=0; i--){
            if( i-1 >=0 && nums[i-1] < nums[i]){
                pivot_index = i-1;
                break;
            }
        }

        if(pivot_index == -1) {
                reverse(nums.begin(),nums.end());
                return;
         }


            int swap_index = -1; // index of just bada element
            for(int j=n-1; j>=pivot_index+1; j--){
                if(nums[j] > nums[pivot_index]){
                  swap_index = j;
                  break;
                }
            }
    
            swap(nums[swap_index],nums[pivot_index]);
        reverse(nums.begin()+pivot_index+1,nums.end());
    }
};