
class Solution {
public:
    bool recursion(vector<int>& nums, int k, int i, int sum,
                   vector<bool>& visited, int target, int count) {

        int n = nums.size();

        if(count == k-1) return true;

        if(sum == target) {
            return recursion(nums, k, 0, 0, visited, target, count+1);
        }

        for(int j=i; j<n; j++) {

            if(visited[j] == false) {

                if(sum + nums[j] <= target) {

                    visited[j] = true;

                    if(recursion(nums, k, j+1, sum+nums[j],
                                 visited, target, count)) {
                        return true;
                    }

                    visited[j] = false;
                }
            }
        }

        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {

        int n = nums.size();
        int totalsum = 0;

        for(int i=0; i<n; i++) {
            totalsum += nums[i];
        }

        if(totalsum % k != 0) return false;

        int target = totalsum/k;

        vector<bool> visited(n, false);

        return recursion(nums, k, 0, 0, visited, target, 0);
    }
};
