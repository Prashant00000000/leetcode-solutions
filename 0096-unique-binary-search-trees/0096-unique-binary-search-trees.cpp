class Solution {
public:
    int numTrees(int n) {
        if(n == 0 || n == 1) return 1;

        int ans = 0;

        for(int i = 0; i < n; i++) {
            ans += numTrees(i) * numTrees(n - 1 - i);
        }

        return ans;
    }
};