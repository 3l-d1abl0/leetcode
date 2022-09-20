class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        
        unordered_set<int> st;
        unordered_set<int> now;
        for(int ele: arr){
            
            
            unordered_set<int> prev(now.begin(), now.end());
            
            now.clear();
            for(int prev_xor: prev){
                now.insert( (prev_xor|ele) );
            }
            now.insert(ele);
            
            for(int ele: now){
                st.insert(ele);
            }
            
        }
        
        
        return st.size();
    }
};