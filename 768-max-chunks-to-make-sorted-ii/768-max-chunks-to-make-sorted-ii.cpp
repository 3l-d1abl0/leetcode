class Solution {
public:
    int maxChunksToSorted(vector<int>& nums) {
                
        int ctr =0;
        stack<int> st;
        
        int largest;
        for(int i= 0; i<nums.size(); i++){
            
            largest = nums[i];
            
            while(!st.empty() && st.top() > nums[i]){
                largest  = max(largest, st.top());
                st.pop();
            }
            
            st.push(largest);
            
        }
            
        return st.size();
    }
};