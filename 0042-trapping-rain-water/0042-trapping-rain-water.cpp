class Solution {
public:
    int pref_max(vector<int>& prefmax, vector<int>& height) {
        int n = prefmax.size();

        prefmax[0] = height[0];

        for(int i = 1; i < n; i++) {
            prefmax[i] = max(prefmax[i-1], height[i]);
        }

        return prefmax[n-1];
    }

    int suffmax(vector<int>& suffixmax, vector<int>& height) {
        int n = suffixmax.size();

        suffixmax[n-1] = height[n-1];

        for(int i = n-2; i >= 0; i--) {
            suffixmax[i] = max(suffixmax[i+1], height[i]);
        }

        return suffixmax[0];
    }

    int trap(vector<int>& height) {
        int n = height.size();
        int total = 0;

        vector<int> prefmax(n);
        vector<int> suffixmax(n);

        pref_max(prefmax, height);
        suffmax(suffixmax, height);

        for(int i = 0; i < n; i++) {
            int left_max = prefmax[i];
            int right_max = suffixmax[i];

            if(height[i] < left_max && height[i] < right_max) {
                total += min(left_max, right_max) - height[i];
            }
        }

        return total;
    }
};