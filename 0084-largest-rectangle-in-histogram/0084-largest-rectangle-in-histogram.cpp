class Solution {
public:
vector<int>NEXT_SE(vector<int>& heights){
    stack<int>st;
    vector<int>ans;
     int n = heights.size();
    for(int i=heights.size()-1; i>=0; i--){
        while(!st.empty() && heights[st.top()] >= heights[i]){
            st.pop();
        }
        if(st.empty()){
            ans.push_back(n);
        }
        else{
      ans.push_back(st.top());
    }
        st.push(i);
    }
    reverse(ans.begin(), ans.end());
    return ans;
    }
vector<int>PREVIOUS_SE(vector<int>& heights){
    stack<int>st;
    vector<int>ans;
     int n = heights.size();
   for(int i=0; i<heights.size(); i++){
        while(!st.empty() && heights[st.top()] >= heights[i]){
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
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int>NSE = NEXT_SE(heights);
        vector<int>PSE = PREVIOUS_SE(heights);
        int maxarea = INT_MIN;
        for(int i=0; i<heights.size(); i++){
             int width = NSE[i] - PSE[i] - 1;
             int area = heights[i] * width;
             maxarea = max(maxarea,area);
        }
        return maxarea;
    }
};