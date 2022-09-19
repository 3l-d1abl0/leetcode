class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        
        unordered_map<int, int> st;
        
        for(int ele: nums)
            st[ele]++;
        
        vector<int> ans;
        for(int ele: nums){
            
            if(st[ele] >1) continue;
            
            if(st.find(ele-1)== st.end() && st.find(ele+1)== st.end()){
                ans.push_back(ele);
            }
        }//for
        
        
        return ans;
    }
};