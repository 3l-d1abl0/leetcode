class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        
        int N = matrix.size();
        int M = matrix[0].size();
        /*
        First element of each row is an Indicator of that row,
        First elemen tof each col is an Indicator of that col
        
        Since row0 and col0 have a collision, we take seperate variable for col0
        
        */
        
        
        bool col0 = false;
        
        
        for(int i=0; i<N; i++){
            
            if(matrix[i][0]==0)
                col0=true;
            
            for(int j=1; j<M; j++){
                
                if(matrix[i][j]==0){
                    matrix[i][0] = 0; //set row
                    matrix[0][j] = 0; //set col
                    

                }
            }
        }//for i
        
        
        for(int i=N-1; i>=0; i--){
            for(int j=M-1; j>=1; j--){
                
                if(matrix[i][0]==0 || matrix[0][j]==0){
                    matrix[i][j]=0;
                }
                
            }
            
            if(col0==true)
                matrix[i][0] =0;
        }
    }
};