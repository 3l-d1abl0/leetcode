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
    
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        
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
};