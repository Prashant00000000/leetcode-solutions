class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();

        for(int i = 0; i < n; i++) {

            int j;

            for(j = i + 1; j < i + n; j++) {

                int index = j % n; 

                if(nums[i] < nums[index]) {
                    ans.push_back(nums[index]);
                    break;
                }
            }
            if(j == i + n) {
                ans.push_back(-1);
            }
        }

        return ans;
    }
};