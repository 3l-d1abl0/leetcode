class Solution {
public:
    
    int bfs(vector<vector<int>> &grid, queue<pair<int,int>> &q){
        
        
        vector<pair<int,int>> dir {
            {-1, 0},
            {0,  1},
            {1,  0},
            {0, -1}
        };
        
        
        int dist =0;
        int N = grid.size();
        int M = grid[0].size();
        
        while(!q.empty()){
            
            int sz = q.size();
            
            for(int i=0; i<sz; i++){
                
                auto [x, y] = q.front();
                q.pop();
                
                //look in 4 dir
                for(auto [xx, yy]: dir){
                    
                    int newX = x+xx;
                    int newY = y+yy;
                    
                    if(newX<0 || newY<0 || newX>=N || newY >=M || grid[newX][newY]==1)
                        continue;
                    
                        q.push({newX, newY});
                        grid[newX][newY] = 1; 
                    
                }
            }
            
            dist++;
        }
        
        return dist;
    }//bfs
    
    
    int maxDistance(vector<vector<int>>& grid) {
        
        int N = grid.size();
        int M = grid[0].size();
        
        queue<pair<int,int>> q;
        
        // step 1 : push all coordinates of land
        for(int i=0 ; i<N ; i++)
            for(int j=0 ; j<N ; j++)
                if(grid[i][j] == 1)
                    q.push({i,j});
    
        //Check if cell with No Waters
        if(q.size() == N*M)
            return -1;
        
        int ans = bfs(grid, q);
        
        
        return ans-1;
    }
};