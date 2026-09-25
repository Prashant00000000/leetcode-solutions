class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> maxi;  // maximum maintain karega
        deque<int> mini;  // minimum maintain karega
        int n = nums.size();
        int maxlen = 0;
         int left = 0;
        for(int i=0; i<n; i++){
            maxi.push_back(i);
            mini.push_back(i);

            while(!maxi.empty() && nums[maxi.back()] <= nums[i]){
                maxi.pop_back();
            }
             while(!mini.empty() && nums[mini.back()] >= nums[i]){
                mini.pop_back();
            }
              maxi.push_back(i);
              mini.push_back(i);

              while(nums[maxi.front()] - nums[mini.front()] > limit ){
               if(maxi.front() == left){
                maxi.pop_front();
               }
               if(mini.front() == left){
                mini.pop_front();
               }
               left++;
              }
              maxlen = max(maxlen, i-left+1);
           }
           return maxlen;
    }
};