class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int l1 = 0;
        int h1 = n-1;
        vector<int>ans;
          int first = -1;
        while(l1<=h1){
            int mid = l1 + (h1-l1)/2;
            if(nums[mid]==target){
                first = mid;
                h1 = mid-1;
            }
            else if(nums[mid] < target){
                l1 = mid+1;
            }
            else{
                h1 = mid-1;
            }
            
        }

        int l2 = 0;
        int h2 = n-1;
         int second = -1;
        while(l2<=h2){
            int mid = l2 + (h2-l2)/2;
           
            if(nums[mid]==target){
                second = mid;
                l2 = mid+1;
                }
            
            else if(nums[mid] < target){
                l2 = mid+1;
            }
            else{
                h2 = mid-1;
            }
        }
        ans.push_back(first);
        ans.push_back(second);
        if(ans.empty()){
            return {-1,-1};
        }
        return ans;
    }
};