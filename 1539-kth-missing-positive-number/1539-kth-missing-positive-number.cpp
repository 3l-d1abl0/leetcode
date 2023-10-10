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
        
        /*   0 1 2 3 4
            [2,3,4,7,11]
             1 2 3 4  5  6
   missing-        3  6
        */  
        
        /*int low = 0, high = arr.size() -1;
        
        while(low <= high){
            
            int mid = low +(high-low)/2;
            
            int expected = mid+1;
            int missing = arr[mid] - expected;
            
            if(missing<k){  //try to get closer to k
                low = mid+1;
            }else{
                high = mid-1;
            }
        }*/
        
        //int expected = l+1;
        //int missing = arr[l] - expected;
        /*
            arr[high] + ( k- missing)
            arr[high] + ( k- arr[high] + expected)
            arr[high] + ( k- arr[high] + high+1)
            
            high+1+k
            high+1  +k
            low+k
        */
        //return high+1+k;
        
        int low = -1, high = arr.size();
        
        while(high-low > 1){
            
            int mid = low +(high-low)/2;
            
            int expected = mid+1;
            int missing = arr[mid] - expected;
            
            if(missing<k){  //try to get closer to k
                low = mid;
            }else{
                high = mid;
            }
        }//while
        
        /*middingMore = k - arr[low] + low +1
            arr[low] + missing more
            arr[low] + k - arr[low] + low +1
            low+1+k
        */
        
        //cout<<low<<" "<<high<<endl;
        return low+1+k;
    }
    
     int findKthPositive(vector<int>& A, int k) {
         
         //return method1(A, k);
           return method2(A, k);
    }
};