class Solution {
public:
bool recursion(int i,vector<int>& arr, vector<bool>&visited){
    int n = arr.size();
    if( i < 0 || i>=n || visited[i]){
        return false;
    }
    if(arr[i] == 0) return true;
   visited[i] = true;
   
     bool option1 = recursion(i + arr[i], arr,visited);
     bool option2 =   recursion(i - arr[i],arr,visited);
    return option1 || option2;
}
    bool canReach(vector<int>& arr, int start) {
       vector<bool> visited(arr.size(), 0);
        return recursion(start,arr,visited);
    }
};