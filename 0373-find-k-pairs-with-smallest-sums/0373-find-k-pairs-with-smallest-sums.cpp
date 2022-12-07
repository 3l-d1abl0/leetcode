struct Node{
    int sum, i, j;
};

struct CompareFn{
    
    bool operator()(Node const &n1, Node const &n2){
        return n1.sum > n2.sum;
    }
    
};

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& A, vector<int>& B, int k) {
        
        
        int N = A.size();
        int M = B.size();
        
        priority_queue<Node, vector<Node> , CompareFn> minHeap;
        
        for(int i=0; i<N; i++){
            minHeap.push({ A[i]+B[0], i, 0 });
        }
        
        vector<vector<int>> ans;
        while(!minHeap.empty() && k>0){
            
            Node top = minHeap.top();
            minHeap.pop();
            
            
            ans.push_back({A[top.i], B[top.j]});
            k--;
            
            if(top.j+1 == M)    //exhausted
                continue;
            
            minHeap.push({A[top.i]+B[top.j+1], top.i, top.j+1});
            
        }//while
        
        
        return ans;
        
    }
};