class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int h = n-1;
        int ans = 0;
        while(l<h){
            int mid = l + (h-l)/2;
            if(mid > 0 && mid + 1 < n && nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]){
                return mid;
            }
            else if(nums[mid] < nums[mid+1]){
                l = mid+1;
            }
            else{
                h = mid;
            }
        }
        return l;
    }
};