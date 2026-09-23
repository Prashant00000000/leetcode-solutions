class Solution {
public:

    // Next Greater
    vector<int> nextgreater_Ele(vector<int>& arr){
        stack<int> st;
        vector<int> ans;

        for(int i = arr.size()-1; i >= 0; i--){
            while(!st.empty() && arr[st.top()] < arr[i]){
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

        reverse(ans.begin(), ans.end());
        return ans;
    }

    // Previous Greater
    vector<int> prevgreater_Ele(vector<int>& arr){
        vector<int> ans;
        stack<int> st;

        for(int i = 0; i < arr.size(); i++){
            while(!st.empty() && arr[st.top()] <= arr[i]){
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

    // Next Smaller
    vector<int> nextsmaller_Ele(vector<int>& arr){
        stack<int> st;
        vector<int> ans;

        for(int i = arr.size()-1; i >= 0; i--){
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

        reverse(ans.begin(), ans.end());
        return ans;
    }

    // Previous Smaller
    vector<int> prevsmaler_Ele(vector<int>& arr){
        vector<int> ans;
        stack<int> st;

        for(int i = 0; i < arr.size(); i++){
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

    long long subarrayMax(vector<int>& arr){
        long long total = 0;

        vector<int> NGE = nextgreater_Ele(arr);
        vector<int> PGE = prevgreater_Ele(arr);

        for(int i = 0; i < arr.size(); i++){
            long long left = i - PGE[i];
            long long right = (NGE[i] == -1 ? arr.size() : NGE[i]) - i;

            total += left * right * arr[i];
        }

        return total;
    }

    long long subarrayMin(vector<int>& arr){
        long long total = 0;

        vector<int> NSE = nextsmaller_Ele(arr);
        vector<int> PSE = prevsmaler_Ele(arr);

        for(int i = 0; i < arr.size(); i++){
            long long left = i - PSE[i];
            long long right = (NSE[i] == -1 ? arr.size() : NSE[i]) - i;

            total += left * right * arr[i];
        }

        return total;
    }

    long long subArrayRanges(vector<int>& nums) {

        long long maximum = subarrayMax(nums);
        long long minimum = subarrayMin(nums);

        return maximum - minimum;
    }
};