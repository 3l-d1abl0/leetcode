class Solution {
public:
    
    //Using Max Heap
    void printQ(priority_queue<int, vector<int>, greater<int> > pq){
        
        while(!pq.empty()){
            
            cout<<pq.top()<<" "; pq.pop();
        }
        
        cout<<endl;
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        
        priority_queue<int, vector<int>, greater<int> > pq;
        
        for(vector<int>::iterator it = nums.begin(); it != nums.end(); it++){
            
            if(pq.size() < k){
                pq.push(*it);
            }else{
                
                if(*it > pq.top()){
                    
                    pq.pop();
                    pq.push(*it);
                    
                    
                   // printQ(pq);
                }
            }
            
        }//for
        
        
        return pq.top();
        
    }
};