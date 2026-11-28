class Solution {
public:

bool recursion(vector<int>& matchsticks,int totalsides, int i, int sum,vector<bool>& visited, int target, int count) {

      int n = matchsticks.size();
      if(count == totalsides-1) return true;

      if(sum == target) {
            return recursion(matchsticks, totalsides, 0, 0, visited, target, count+1);
        }

        for(int j=i; j<n; j++) {

            if(visited[j] == false) {

                if(sum + matchsticks[j] <= target) {

                    visited[j] = true;

                    if(recursion(matchsticks,totalsides, j+1, sum+matchsticks[j],
                                 visited, target, count)) {
                        return true;
                    }

                    visited[j] = false;
                }
            }
        }

        return false;
    }

  


    bool makesquare(vector<int>& matchsticks) {
        int n = matchsticks.size();
        int totalsum = 0;
        for(int i=0; i<n; i++){
            totalsum+=matchsticks[i];
        }
        if(totalsum % 4 != 0) return false;
        int target = totalsum/4;
        vector<bool> visited(n, false);
        int i = 0;
        int sum = 0;
        int count = 0;
        int totalsides = 4;
         return recursion(matchsticks, totalsides, i, sum, visited, target, count);
    }
};