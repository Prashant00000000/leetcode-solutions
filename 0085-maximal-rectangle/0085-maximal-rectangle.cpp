
class Solution {
public:

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        vector<int>NSE(n);
        vector<int>PSE(n);

        stack<int>st;

        // NEXT SMALLER ELEMENT
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }

            if(st.empty()){
                NSE[i] = n;
            }
            else{
                NSE[i] = st.top();
            }

            st.push(i);
        }

        // Clear stack before calculating PSE
        while(!st.empty()) st.pop();

        // PREVIOUS SMALLER ELEMENT
        for(int i=0; i<n; i++){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }

            if(st.empty()){
                PSE[i] = -1;
            }
            else{
                PSE[i] = st.top();
            }

            st.push(i);
        }

        int maxarea = 0;

        for(int i=0; i<n; i++){
            int width = NSE[i] - PSE[i] - 1;
            int area = heights[i] * width;

            maxarea = max(maxarea, area);
        }

        return maxarea;
    }


    int maximalRectangle(vector<vector<char>>& matrix) {

        int n = matrix.size();

        if(n == 0) return 0;

        int m = matrix[0].size();

        vector<vector<int>> prefix(n, vector<int>(m, 0));

        for(int j=0; j<m; j++){

            for(int i=0; i<n; i++){

                if(matrix[i][j] == '0'){
                    prefix[i][j] = 0;
                }
                else{
                    if(i == 0){
                        prefix[i][j] = 1;
                    }
                    else{
                        prefix[i][j] = prefix[i-1][j] + 1;
                    }
                }
            }
        }

        int ans = 0;

        for(int i=0; i<n; i++){

            vector<int>heights;

            for(int j=0; j<m; j++){
                heights.push_back(prefix[i][j]);
            }

            int area = largestRectangleArea(heights);

            ans = max(ans, area);
        }

        return ans;
    }
};
