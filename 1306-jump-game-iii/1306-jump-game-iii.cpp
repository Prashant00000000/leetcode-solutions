class Solution {
public:
    bool recursion(int i, vector<int>& arr) {
        if (arr[i] == 0) return true;
        if (arr[i] < 0) return false;

        int jump = arr[i];  
        arr[i] = -1;       

        int option1 = -1;
        if (i + jump < arr.size()) {
            option1 = i + jump;
        }

        int option2 = -1;
        if (i - jump >= 0) {
            option2 = i - jump;
        }

        if (option1 != -1 && recursion(option1, arr))
            return true;

        if (option2 != -1 && recursion(option2, arr))
            return true;

        return false;
    }

    bool canReach(vector<int>& arr, int start) {
        return recursion(start, arr);
    }
};