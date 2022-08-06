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
            int missing = A[mid] - (mid+1);
            if (missing < k)  //A[m]-(m+1)   --> This gives umber of missing number before m'th index
                low = mid + 1;
            else
                high = mid-1;
           //cout<<high<<" ";
        }
         //cout<<low<<"+"<<k<<endl;
        return low + k;
    }
};