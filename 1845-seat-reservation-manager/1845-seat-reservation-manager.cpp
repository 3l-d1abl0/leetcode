class SeatManager {
    /*
        Method1: keep a min Heap of n numbers
        when reserving : pop the top element from the heap
        When unreserving: push it back
        
        
        
        Method2: 
        Keep a last counter/Index to serve the reserve number
        When reserving :
            if the men hep is full
                pop from the min heap
            otherwise return the last Index/counter
            
            
        Whne unreserving:
            if the unreserved number is th last Index, decrese the last Index
            if not push it in  amin heap
    
    */
    
private:
    int last;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
public:
    SeatManager(int n) {
        last =0;    
    }
    
    int reserve() {
        
        if(minHeap.empty()){
            return ++last;
        }else{
            int seat = minHeap.top();
            minHeap.pop();
            
            
            return seat;
        }
    }
    
    void unreserve(int seatNumber) {
     
        if(last == seatNumber){
            last--;
        }else{
            minHeap.push(seatNumber);
        }
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */