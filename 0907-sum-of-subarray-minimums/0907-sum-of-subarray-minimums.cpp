class Solution {
public:
vector<int> nextsmaller_Ele(vector<int>& arr){
    stack<int>st;
    vector<int>ans;
for(int i=arr.size()-1; i>=0; i--){
    while(!st.empty() && arr[st.top()] > arr[i]){
        st.pop();
      }
     if(st.empty()){
      ans.push_back(-1);
     }
     else{
         ans.push_back(st.top());
     }
    st.push(i);
     }
     reverse (ans.begin(),ans.end());
     return ans;
}
vector<int> prevsmaler_Ele(vector<int>& arr){
      vector<int>ans;
      stack<int>st;
        for(int i=0; i<arr.size(); i++){
          while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            if(st.empty()){
                ans.push_back(-1);
            }
            else{
                ans.push_back(st.top());
            }
           st.push(i);
        }
        return ans;
}
    int sumSubarrayMins(vector<int>& arr) {
        long long total = 0;
        int mod = 1e9 + 7;
     vector<int> NSE = nextsmaller_Ele(arr);
     vector<int> PSE = prevsmaler_Ele(arr);
        for(int i=0; i<arr.size(); i++){
            int left = i - PSE[i];
            int right = (NSE[i] == -1 ? arr.size() : NSE[i]) - i;
            // contribution of both left and  right
           total = (total + left * 1LL * right * arr[i]) % mod;
        }
        return total;
    }
};