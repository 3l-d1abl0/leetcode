class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        
        int N= grid.size();
        int M = grid[0].size();
        
        for(int i=0; i<N; i++){
            
            for(int j=0; j<M; j++){
                
                
                if((i==0 || j==0 || i==N-1 || j==M-1) && (grid[i][j]==0) ){
                   dfs(i, j, grid); 
                }
                
            }
            
        }//for
        
        int ctr =0;
        
        for(int i=0; i<N; i++){
            
            
            for(int j=0; j<M; j++){
                    
                if(grid[i][j]==0){
                    
                    dfs(i, j, grid);
                    
                    ctr++;
                }
                
                
            }
            
        }
        
        return ctr;
        
    }//closed
    
    void dfs(int i, int j, vector<vector<int>> &grid){
        
        if(i<0 || j<0 || i>= grid.size() || j>= grid[0].size() || grid[i][j]!=0){
            return ;
        }
        
        
        grid[i][j]=2;
        
        dfs(i-1, j, grid); 
        dfs(i, j+1, grid); 
        dfs(i+1, j, grid); 
        dfs(i, j-1, grid); 
        
        
    }
    
};