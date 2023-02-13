class Solution {
public:
    int candy(vector<int>& r) {
        
        int N= r.size();
        vector<int> left(N, 1);
        vector<int> right(N, 1);
        
        for(int i=1; i<N; i++){
            
            if(r[i]>r[i-1]){
                left[i] = left[i-1]+1;
            }
        }
        
        for(int i=N-2; i>=0; i--){
            
            if(r[i]>r[i+1]){
                right[i] = right[i+1]+1;
            }
        }
        
        int sum =0;
        
        for(int i=0; i<N; i++){
            sum +=max(left[i], right[i]);
        }
        
        
        return sum;
    }
};