class Solution {
public:

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<int>ans;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                bool first = true,second = true,third = true,fourth = true;
         if(j+1<m&&mat[i][j] < mat[i][j+1]){
                  first = false;
         }
         if(i+1<n && mat[i][j] < mat[i+1][j]){
            second = false;
         }
         if(i-1>=0 && mat[i][j] < mat[i-1][j]){
            third = false;
         }
         if(j-1>=0 && mat[i][j] < mat[i][j-1]){
            fourth = false;
         }
        if(first && second && third && fourth ){
            ans.push_back(i);
             ans.push_back(j);
             return ans;
        }
        }
        
    }
    return ans;
    }
};