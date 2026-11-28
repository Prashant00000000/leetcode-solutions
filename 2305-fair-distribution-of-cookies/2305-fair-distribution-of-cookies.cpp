class Solution {
public:
int recursion(int i, vector<int>& cookies, int k,vector<int>& sum){
    // base case
if(i == cookies.size()){
    int maxi_sum = INT_MIN;
    for(int j=0; j<k; j++){
        maxi_sum = max(maxi_sum,sum[j]);
    }
    return maxi_sum;
}

int n = cookies.size();

int mini = INT_MAX;
    for(int j=0; j<k; j++){
        sum[j]+=cookies[i];
    int maxi_sum = recursion(i+1,cookies,k,sum);
   mini = min(mini,maxi_sum);
        // backtracking
        sum[j]-=cookies[i];
    }
return mini;
}

    int distributeCookies(vector<int>& cookies, int k) {
       int n = cookies.size();
       vector<int>sum(k,0);
        return recursion(0,cookies,k,sum);
    }
};