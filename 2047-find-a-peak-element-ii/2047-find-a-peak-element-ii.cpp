class Solution {
public:
    
    //Finds the col of the max element in the midRow
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
        
        
        //O(N logM)
        int rows = mat.size();
        int cols = mat[0].size();
        
       
        int topRow = 0;
        int botRow = rows-1;
        
        while(topRow <= botRow){
            
            
            int midRow = topRow +(botRow-topRow)/2;
            
            //Finds the col of the max element in the midRow
            int col = max_element(mat, midRow, cols);
            
            int top = ((midRow-1) >= 0) ? mat[midRow-1][col] : -1;  //check for Top Row
            int bottom = ((midRow+1) <=rows-1) ? mat[midRow+1][col]: -1;    //check for bottom Row
            
           
            //3. if this ele is the one
            if(top < mat[midRow][col] && bottom < mat[midRow][col])
                return {midRow, col};
            
            //4. elsse go to the greates neighour
            if(bottom > mat[midRow][col])
                topRow = midRow+1;
            else
                botRow= midRow-1;
        }//while
        
        
        return {-1, -1};
        
    }
};