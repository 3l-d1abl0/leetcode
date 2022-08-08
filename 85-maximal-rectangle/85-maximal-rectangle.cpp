class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        int R = matrix.size();
        int C = matrix[0].size();
        
        int maxx = -1;
        vector<int> row(C);
        
        vector<int> defaultLeft(C);
        vector<int> defaultRight(C);
        
        for(int i=0; i<C; i++){
            defaultLeft[i] = i+1;
            defaultRight[i]= C-i;
        }
        
        for(int i=0; i<R; i++){
            
            
            for(int j=0; j<C; j++){
                
                if(i==0){
                    row[j] = matrix[i][j]-'0';
                }else{
                    if(matrix[i][j]=='0')
                        row[j] = 0;
                    else
                        row[j] +=matrix[i][j]-'0';
                }
                
            }
            
            //calculate for individual cumulative Row
            maxx = max(maxx, findLargestInHistogram(row, defaultLeft, defaultRight));
            
        }//for
        
        
        
        return maxx;
        
    }
    
    
    int findLargestInHistogram(vector<int> &row, vector<int> &defaultLeft, vector<int> &defaultRight){
        
        int N = row.size();
        
        vector<int> left(defaultLeft.begin(), defaultLeft.end());
        vector<int> right(defaultRight.begin(), defaultRight.end());
        
        stack<int> st;
        for(int i=0; i<N; i++){
            
            while(!st.empty() && row[st.top()] > row[i]){
                right[st.top()] = i-st.top();
                st.pop();
            }
            
            if(!st.empty()){
                left[i] = i-st.top();
            }
            
            st.push(i);
            
            
            
        }
        
        
        int maxx = INT_MIN;
        for(int i=0; i<N; i++){
            maxx = max(maxx, row[i]*(right[i]+left[i]-1));
        }
        
        return maxx;
        
    }
};