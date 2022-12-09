struct Node{
  
    double dist;
    int x, y;
};

struct CompareFn{
    
    bool operator()( Node const &n1, Node const &n2){
        return n1.dist < n2.dist; //max Heap
    }
    
};

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        priority_queue<Node, vector<Node>, CompareFn> maxHeap;
        
        for(auto row: points){
            
            double dist = sqrt( pow( row[0],2) +pow(row[1],2) );
            //cout<<"d= "<<dist<<endl;
            if(maxHeap.empty()){
                maxHeap.push({dist, row[0], row[1]});
                continue;
            }
            
            //if(!maxHeap.empty() && dist < maxHeap.top().dist){
                maxHeap.push({dist, row[0], row[1]});
            //}
            
            while(maxHeap.size() > k){
                maxHeap.pop();
            }
        }
        
        vector<vector<int>> ans;
        while(!maxHeap.empty()){
            ans.push_back( {maxHeap.top().x, maxHeap.top().y} );
            maxHeap.pop();
        }
        
        
        return ans;
    }
};