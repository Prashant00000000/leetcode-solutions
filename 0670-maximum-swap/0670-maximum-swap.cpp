class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int n = s.size();
        vector<int>rightmax(n);

        rightmax[n-1] = n-1;

        for(int i=n-2; i>=0; i--){
            if(s[i] > s[rightmax[i+1]]){
                rightmax[i] = i;
            }
            else{
                rightmax[i] = rightmax[i+1];
            }
        }
        // find first position where the benefical swap happens i.e if I swap a large no with left starting left no 
        // then automatically my no becomes large in single swap
        for(int i=0; i<n; i++){
            int index = rightmax[i];
            if(s[i] < s[index]){
                swap(s[i],s[index]);
                break;
            }
        }
        return stoi(s);
    }
};