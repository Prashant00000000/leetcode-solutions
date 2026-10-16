class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1, 0);

        dp[0] = 1;
        dp[1] = 1;

        for(int j = 2; j <= n; j++) { // starts from 2 because we ahve already calculated for 0 and 1
            for(int i = 0; i < j; i++) { // it is basically the value of i which is mentioned in cataln no formuales
                dp[j] += dp[i] * dp[j - 1 - i];
            }
        }

        return dp[n];
    }
};