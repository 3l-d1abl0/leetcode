class StockSpanner {
public:
    stack<int> st;
    vector<int> arr;
    int idx;
    StockSpanner() {
        
        idx =0;
    }
    
    int next(int price) {
        
        int span;
        while(!st.empty() && arr[st.top()] <= price){
            st.pop();   
        }
        
        if(st.empty())
            span=idx+1;
        else
            span= idx - st.top();
        
        arr.push_back(price);
        st.push(idx);
        
        idx++;
        
        
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */