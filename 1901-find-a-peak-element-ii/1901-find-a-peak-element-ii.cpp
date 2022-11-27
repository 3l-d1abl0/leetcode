class Solution {
public:
    
    int max_element(vector<vector<int>> &mat, int midRow, int cols){
        
        int maxx = -1;
        int col =0;
        
        for(int i=0; i<cols; i++){
            
            if(mat[midRow][i]>=maxx){
                maxx = mat[midRow][i];
                col=i;
            }
        }//for
        
        return col;
        
    }
    
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        
        int rows = mat.size();
        int cols = mat[0].size();
        
       
        int topRow = 0;
        int botRow = rows-1;
        
        while(topRow <= botRow){
            
            
            int midRow = topRow +(botRow-topRow)/2;
            
            int col = max_element(mat, midRow, cols);
            
            
            
            //1. Top most Row
            if(midRow==0){
                
                if(mat[midRow+1][col] < mat[midRow][col])
                    return {midRow, col};
                else{
                    topRow= midRow+1;
                    continue;
                }
            }
          
            //2. Bottom Row
            if(midRow == rows-1){
                
                //cout<<mat[midRow-1][col]<<" < "<<mat[midRow][col]<<endl;
                if(mat[midRow-1][col] < mat[midRow][col])
                    return {midRow, col};
                else{
                    botRow = midRow-1;
                    continue;
                }
                
            }
            
           
            //3. if this ele is the one
            if(mat[midRow-1][col] < mat[midRow][col] && mat[midRow+1][col] < mat[midRow][col])
                return {midRow, col};
            
            //4. elsse go to the greates neighour
            if(mat[midRow+1][col] > mat[midRow][col])
                topRow = midRow+1;
            else
                botRow= midRow-1;
        }//while
        
        
        return {-1, -1};
        
    }
};