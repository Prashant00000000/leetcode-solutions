class Solution {
public:
    int findMin(vector<int>& nums) {
        int s = 0;
        int e = nums.size() - 1;

        while (s < e) {
            int mid = s + (e - s) / 2;

            if (nums[mid] > nums[e]) {
                // Minimum right side mein hai
                s = mid + 1;
            }
            else {
                // Minimum mid ya left side mein hai
                e = mid;
            }
        }

        return nums[s];
    }
};