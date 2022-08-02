class MyStack {
public:
    
    queue<int> *q;
    MyStack() {
        q = new queue<int>;
    }
    
    void push(int x) {
        
        q->push(x);
        int sz = q->size();
        for(int i=1; i<sz; i++){
            q->push(q->front());
            q->pop();
        }
        
        
    }
    
    int pop() {
        
        int ans = q->front();
        q->pop();
        
        return ans;
    }
    
    int top() {
        return q->front();
    }
    
    bool empty() {
        
        return q->empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */