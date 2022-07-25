class KthLargest {
    
    int k;
    priority_queue<int, vector<int>, greater<int>> *pq;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        
        // if(nums.size()==0)
        //     this->pq = new priority_queue<int, vector<int>, greater<int>>;
        // else
            this->pq = new priority_queue<int, vector<int>, greater<int>> (nums.begin(), nums.end()); 
        
        
        while(pq->size()>k)
            pq->pop();
    }
    
    int add(int val) {
        
        if(pq->empty())
            pq->push(val);
        else if(k>pq->size())
            pq->push(val);
        else if(val>pq->top()){
            pq->pop();
            pq->push(val);
        }
        
        return pq->top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */