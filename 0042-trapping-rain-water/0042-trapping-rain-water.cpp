
class Solution {
public:
    vector<int> leftmax(vector<int>& height, vector<int>& prefix_left_max) {
        prefix_left_max.resize(height.size());
        prefix_left_max[0] = height[0];

        for(int i = 1; i < height.size(); i++) {
            prefix_left_max[i] = max(prefix_left_max[i-1], height[i]);
        }

        return prefix_left_max;
    }

    vector<int> rightmax(vector<int>& height, vector<int>& prefix_right_max) {
        prefix_right_max.resize(height.size());
        prefix_right_max[height.size()-1] = height[height.size()-1];

        for(int i = height.size()-2; i >= 0; i--) {
            prefix_right_max[i] = max(prefix_right_max[i+1], height[i]);
        }

        return prefix_right_max;
    }

    int trap(vector<int>& height) {
        if(height.empty()) return 0;

        vector<int> Lmax;
        vector<int> Rmax;
        int total = 0;

        Lmax = leftmax(height, Lmax);
        Rmax = rightmax(height, Rmax);

        for(int i = 0; i < height.size(); i++) {
            if(Lmax[i] > height[i] && Rmax[i] > height[i]) {
                total += min(Lmax[i], Rmax[i]) - height[i];
            }
        }

        return total;
    }
};
