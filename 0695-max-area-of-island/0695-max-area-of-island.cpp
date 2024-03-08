class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int N = grid.size();
        int M = grid[0].size();
        
        int maxi =0;
        
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                if(grid[i][j]==1){
                    int cnt = 1+dfs(i, j, grid);
                    maxi = max(cnt, maxi);
                    
                }
                               
            }
            
        }//for
        
                               
        return maxi;
    }
                               
    int dfs(int x, int y, vector<vector<int>>& grid){
        
        grid[x][y] = 0;
        int cnt = 0;
        
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, 1, -1};
        
        for(int i=0; i<4; i++){
            
            int newX = x+ dx[i];
            int newY = y+dy[i];
            
            if(newX>=0 && newX<grid.size() && newY>=0 && newY<grid[0].size() && grid[newX][newY] ==1){
                
                
                    cnt += (1+ dfs(newX, newY, grid));
            
            }
            
            
        }//for
        
        return cnt;
    }
};