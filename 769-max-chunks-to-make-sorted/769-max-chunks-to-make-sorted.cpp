class Solution {
public:
    int maxChunksToSorted(vector<int>& nums) {
        
        /*
        int ctr =0;
        stack<int> st;
        
        for(int i= nums.size()-1; i>=0; i--){
            
            while(!st.empty() && nums[i] < st.top()){
                ctr++;
                st.pop();
            }
            
            st.push(nums[i]);
            
        }
            
        if(!st.empty()) ctr++;
            
            
        return ctr;*/
        
        int maxx = INT_MIN;
        int chunk =0;
        
        for(int i=0 ;i<nums.size(); i++){
            
            maxx = max(maxx, nums[i]);
            
            if(maxx==i)
                chunk ++;
        }
        
        return chunk;
    }
};