class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int>st;
        int n = nums.size();
        int third_no = INT_MIN;
        for(int i=n-1; i>=0; i--){
            if(nums[i] < third_no) return true;
            while(!st.empty() && st.top() < nums[i]){
              third_no =  st.top();
              st.pop();

            }
            st.push(nums[i]);
        }
        return false;
    }
};