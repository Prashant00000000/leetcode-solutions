class StockSpanner {
public:
    stack<int> st;
    vector<int> arr;

    StockSpanner() {
    }

    int next(int price) {
        arr.push_back(price);
        int i = arr.size() - 1;

        while(!st.empty() && arr[st.top()] <= price) {
            st.pop();
        }

        int span;

        if(st.empty()) {
            span = i + 1;
        }
        else {
            span = i - st.top();
        }

        st.push(i);

        return span;
    }
};