class MedianFinder {
public:
    MedianFinder() {
        
    }
    
    priority_queue<int> maxQ;
    priority_queue<int, vector<int>, greater<int>> minQ;
    
    void addNum(int num) {
        
        if(maxQ.empty()){
            maxQ.push(num);
            return;
        }
        
        if (maxQ.size() == minQ.size()){
            
            
            if(!minQ.empty() && num >= minQ.top()){
             // cout<<"1"<<endl;
                 auto temp = minQ.top();
               minQ.pop();
               maxQ.push(temp);
                
                minQ.push(num);
            }else{
              //  cout<<"2"<<endl;
                maxQ.push(num);
            }
        }else{
            
            if( num<= maxQ.top()){
                auto temp = maxQ.top();
                maxQ.pop();
                minQ.push(temp);
                maxQ.push(num);
            }else{
                minQ.push(num);
            }
            
        }
        
        
    }
    
    double findMedian() {
        
        if(maxQ.size() == minQ.size()){
            //cout<<maxQ.top()<<"--"<<minQ.top()<<endl;
            return (maxQ.top()+minQ.top())/2.0;
        }else{
            //cout<<"----"<<maxQ.top()<<endl;
            return maxQ.top();
        }
        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */