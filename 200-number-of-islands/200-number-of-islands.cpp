class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
     
        int comp =0;
        
        int N = grid.size();
        int M = grid[0].size();
        
        int cmp =0;
        
        vector<vector<int>> dir{ {-1, 0}, {0,1}, {1, 0}, {0, -1} };
        
        for(int i=0; i<N; i++){
            
            
            for(int j=0; j<M; j++){
                
                if(grid[i][j]=='1'){
                    grid[i][j]=='2';
                    cmp ++; dfs(i, j, grid, dir, N, M);
                    
                    
                }
                
                
            }
            
            
            
        }
        
        
        return cmp;
        
    }//numIslands
    
    void dfs(int row, int col, vector<vector<char>> &grid, vector<vector<int>> &dir, int N, int M){
        
        //grid[row][col]='-1';
        
        for(int k=0; k<4 ; k++){
            
            
            if(row+dir[k][0] < 0 || col+dir[k][1]<0 || row+dir[k][0] >= N || col+dir[k][1] >= M)
                continue;
            
            
            
            if(grid[row+dir[k][0]][col+dir[k][1]] =='1'){
                grid[row+dir[k][0]][col+dir[k][1]] ='2';
               dfs(row+dir[k][0], col+dir[k][1], grid, dir, N, M);
            }
            
            
            
        }
        
        
    }
    
};