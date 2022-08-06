class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        
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
};