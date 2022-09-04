class Solution {
public:
    int firstMissingPositive(vector<int>& arr) {
        
        int N =0;
        
        for(int i=0; i<arr.size(); i++){
            
            if(arr[i]>0){
                swap(arr[i], arr[N]);
                N++;
            }
        }
        
        for(int i=0; i<N; i++){
            
            int idx = abs(arr[i]) - 1;
            if(idx < N){
                arr[idx] =  -abs(arr[idx]);
            }
        }
        
        for(int i=0; i<N; i++){
            if(arr[i] > 0)
                return i+1;
        }
        
        return N+1;
    }
};