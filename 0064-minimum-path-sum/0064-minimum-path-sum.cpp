class Solution {
public:
int solve(vector<vector<int>>& grid,int i,int j,int row,int col){
    if(i>=row || j>=col){
        return 100000000;
    }
    if(i==row-1 && j==col-1){
        return grid[i][j];
    }

       int right = grid[i][j] + solve(grid,i,j+1,row,col);
       int  down = grid[i][j] + solve(grid,i+1,j,row,col);
     return min(right,down);
}
int memoisation(vector<vector<int>>& grid,int i,int j,int row,int col,vector<vector<int>>&dp){
 if(i>=row || j>=col){
        return 100000000;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    if(i==row-1 && j==col-1){
        return grid[i][j];
    }

       int right = grid[i][j] + memoisation(grid,i,j+1,row,col,dp);
       int  down = grid[i][j] + memoisation(grid,i+1,j,row,col,dp);
     return dp[i][j] = min(right,down);
}
    int minPathSum(vector<vector<int>>& grid) {
        int i=0;
        int j = 0;
        int row = grid.size();
        int col = grid[0].size();
      // return solve(grid,i,j,row,col);
      vector<vector<int>>dp(row+1,vector<int>(col+1,-1));
      return memoisation(grid,i,j,row,col,dp);
    }
};