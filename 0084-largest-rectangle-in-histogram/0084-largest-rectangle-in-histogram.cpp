class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        /*
        For every index find smalles element to the left and right
        */
        
        int N = heights.size();
        vector<int> left(N);
        vector<int> right(N);
        
        for(int i=0; i<N; i++){
            left[i] = i+1;  right[i]= N-i;
        }
        //left -> 1, 2, 3, 4
        //right -> 4, 3, 2, 1
        
        stack<int> st;
        
        for(int i=0; i<N; i++){    
            
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
        
        
        /*for(int i=0; i<N; i++){
            cout<<left[i]<<" ";
        }cout<<endl;
        for(int i=0; i<N; i++){
            cout<<right[i]<<" ";
        }cout<<endl;*/
        
        int maxx =-1;
        for(int i=0; i<N; i++){
            //cout<<heights[i]<<" "<<right[i]<<" "<<left[i]<<endl;
            maxx = max(maxx, heights[i]*(right[i]+left[i]-1));
            //cout<<maxx<<endl;
        }
        
        return maxx;
    }
};