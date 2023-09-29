class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        
        int N = heights.size();
        
        vector<int> right(N, 0);
        stack<int> st;
        
        for(int i=0; i<N; i++){
        
            while(!st.empty() && heights[st.top()] < heights[i]){
                
                right[st.top()]++;
                st.pop();
                
            }
            
            if(!st.empty())
                right[st.top()]++;
            
            st.push(i);
        }//for
        
        return right;
    }
};