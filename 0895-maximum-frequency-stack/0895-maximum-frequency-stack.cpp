class FreqStack {
    
private:
    int seq;
    unordered_map<int, int> freq;
    
    struct Node{
        int val, freq, seq;
    };
    
        struct CompareFn{
        
        bool operator()(Node &a, Node &b){
            
            return a.freq == b.freq ? a.seq < b.seq : a.freq < b.freq;
        }
    };

    
    priority_queue<Node, vector<Node> , CompareFn> maxH;
    
public:
    FreqStack() {
        seq =0;
    }
    
    void push(int val) {
        maxH.push({val, ++freq[val], ++seq});
    }
    
    int pop() {
        auto ele = maxH.top();
        maxH.pop();
        freq[ele.val]--;
        //cout<<ele.val<<" "<<ele.freq<<" "<<ele.seq<<endl;
        return ele.val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */