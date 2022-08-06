class Solution {
public:
    /*int findKthPositive(vector<int>& arr, int k) {
        
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
    }*/
    
     int findKthPositive(vector<int>& A, int k) {
       int low = 0;
       int high = A.size()-1 ;
       int mid;
       while (low <= high) {
            mid = (low + high) / 2;
            if (A[mid] - (1 + mid) < k)  //A[m]-(m+1)   --> This gives umber of missing number before m'th index
                low = mid + 1;
            else
                high = mid-1;
        }
        return low + k;
    }
};