class Solution {
public:
    
    int method1(vector<int> &arr, int k){
        unordered_set<int> st;
        for(int ele: arr){
            st.insert(ele);
        }
           
        for(int i=1;; i++){
            
            if(st.find(i) == st.end())
                k--;
            
            if(k==0) return i;
        }
        
        
        return -1;
    }
    
    int method2(vector<int> &arr, int k){
        
        int low = 0, high = arr.size() -1;
        
        while(low <= high){
            
            int mid = low +(high-low)/2;
            
            int missing = arr[mid] - (mid+1);
            
            if(k>missing){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        
        return low+k;
    }
    
     int findKthPositive(vector<int>& A, int k) {
         
         //return method1(A, k);
           return method2(A, k);
    }
};