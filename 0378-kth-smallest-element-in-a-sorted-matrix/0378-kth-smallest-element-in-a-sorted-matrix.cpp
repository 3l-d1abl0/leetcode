struct Node{
    int val, row, col;
};

struct CompareVal {
    bool operator()(Node const& n1, Node const& n2){
        //n1 ordered before n2
        return n1.val > n2.val;
        //return n1.val != n2.val ? n1.val > n2.val : n1.id >n2.id;
    }
};


class Solution {
public:
    int lessThan(vector<vector<int>> &matrix, int num){
        
        
        int N = matrix.size();
        int M = matrix[0].size();
        
        int sum =0;
        for(int i=0; i<N; i++){
        
            int l =-1, r = M;
            
            while(r-l>1){
                
                int mid = l+(r-l)/2;

                if(matrix[i][mid]>num)
                    r=mid;
                else
                    l=mid;
            }
            
            //cout<<l<<"  "<<r<<endl;
            sum += r;
        }
        
        return sum;
    } 
    
    
    int binarySearch(vector<vector<int>> &matrix, int k){
        
        
        long long int l = INT_MAX; long long int r = INT_MAX;
        
        for(int i=0; i<matrix.size(); i++){
            l = l<matrix[i][0]? l : matrix[i][0];
            r = r>matrix[i][matrix.size()-1]?r:matrix[i][matrix.size()-1];
        }
        
        
        l--; r++;
        
        
        while(r-l>1){
            
            
            long long int mid = (l+r)/2;
            
            int cnt = lessThan(matrix, mid);
            //cout<<cnt<<" mid="<<mid<<endl;
            
            if(cnt>=k)
                r=mid;
            else
                l=mid;
        }
        
        //t<<lessThan(matrix, 13)<<endl;
        
       // cout<<l<<" -- "<<r<<endl;
        return r;
        
        
    }
    
    int kthSmallestheap(vector<vector<int>> &matrix, int k){
        
        int rows = matrix.size();
        priority_queue<Node, vector<Node>, CompareVal > minHeap;
        for(int i=0; i<rows; i++){
            minHeap.push({matrix[i][0], i, 0});
        }
        
        int r=0, c=0;
        while(k>0 && !minHeap.empty()){
            
            r= minHeap.top().row;
            c= minHeap.top().col;
            //cout<<r<<" "<<c<<" => "<<matrix[r][c]<<endl;
            minHeap.pop();
            
            if(c+1 < matrix[r].size()){
                minHeap.push({matrix[r][c+1], r, c+1});    
            }
            k--;
        }
        
        return matrix[r][c];
    }
    
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        
        //1. Method1 - heap
        //return kthSmallestheap(matrix, k);
        
        //2. Method2 - BinarySearch
        return binarySearch(matrix, k);
        
    }
};