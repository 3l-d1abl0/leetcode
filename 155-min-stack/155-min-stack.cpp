class MinStack {
public:
    
    int min;
    stack<int > st;
    MinStack() {
        min = INT_MAX;
    }
    
    void push(int val) {
        
        
        if(val <= min){
            st.push(min);
            min = val;
        }
        
        st.push(val);
    }
    
    void pop() {
        
        if(st.top()==min){
            st.pop();
            min = st.top();
        }
        
        st.pop();
        
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */