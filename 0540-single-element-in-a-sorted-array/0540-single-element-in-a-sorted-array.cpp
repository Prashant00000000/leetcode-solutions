class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
         int l = 0;
         int h = n-1;
         while(l<h){
            int mid = l + (h-l)/2;
            if(mid%2==0){
                // even index hai it means 1st occurence
                if( nums[mid]==nums[mid+1]){
                    l = mid+2;
                }
                else{
                    h = mid;
                }
            }
            else{
                // mid odd hai
                if(nums[mid]==nums[mid-1]){
                    l = mid+1;
                }
                else{
                    h = mid;
                }
            }
            
         }
         return nums[l];
    }
};