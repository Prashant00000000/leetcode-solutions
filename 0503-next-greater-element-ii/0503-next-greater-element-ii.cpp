class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();

        if(n == 1){
            ans.push_back(-1);
            return ans;
        }

        for(int i = 0; i < n; i++){

            int j; 
            for(j = i + 1; j < n; j++){
                if(nums[i] < nums[j]){
                    ans.push_back(nums[j]);
                    break;
                }
            }
            if(j == n){
                for(int m = 0; m < i; m++){
                    if(nums[i] < nums[m]){
                        ans.push_back(nums[m]);
                        break;
                    }

                    if(m == i - 1){
                        ans.push_back(-1);
                    }
                }
                if(i == 0){
                    ans.push_back(-1);
                }
            }
        }

        return ans;
    }
};