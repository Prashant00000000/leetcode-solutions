class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        stack<int>st;
        int n = nums.size();
        vector<int>ans;
        int m = k;
        for(int i=0; i<n; i++){
            while(!st.empty() && st.top() > nums[i] && m<k && i!=n-m){
                st.pop();
                m++;
            } 

            if(!st.empty() && m>0){
                st.push(nums[i]);
                m--;
            }
            if(st.empty() && m>0){
            st.push(nums[i]);
            m--;
            }
            
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
           }
           reverse(ans.begin(),ans.end());
           return ans;
    }
};