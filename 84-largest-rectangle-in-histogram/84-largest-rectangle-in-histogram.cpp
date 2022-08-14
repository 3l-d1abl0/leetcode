class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        
        vector<int> left(heights.size());
        vector<int> right(heights.size());
        
        for(int i=0; i<heights.size(); i++){
            left[i] = i+1;  right[i]= heights.size()-i;
        }
        //1, 2, 3, 4
        //4, 3, 2, 1
        stack<int> st;
        for(int i=0; i<heights.size(); i++){
            
            
            
            while(!st.empty() && heights[st.top()]> heights[i]){
                right[st.top()]= i-st.top();
                st.pop();
            }
                                     
            if(!st.empty())
                //left[i] = -1;
            //else                                     
                left[i] = i-st.top();
                                     
            st.push(i);
            
        }
        
        
        /*for(int i=0; i<heights.size(); i++){
            cout<<left[i]<<" ";
        }cout<<endl;
        for(int i=0; i<heights.size(); i++){
            cout<<right[i]<<" ";
        }cout<<endl;*/
        
        int maxx =-1;
        for(int i=0; i<heights.size(); i++){
            //cout<<heights[i]<<" "<<right[i]<<" "<<left[i]<<endl;
            maxx = max(maxx, heights[i]*(right[i]+left[i]-1));
            //cout<<maxx<<endl;
        }
        
        return maxx;
    }
};