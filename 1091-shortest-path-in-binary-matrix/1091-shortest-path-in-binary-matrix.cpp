class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        
        int R = grid.size();
        int C = grid[0].size();
        
        if(grid[0][0] == 1)
            return -1;
        
        vector<vector<int>> dist(R, vector<int>(C, 1e9));
        
        queue< pair<int, int> > Q;
        
        dist[0][0] =1;
        Q.push( {0,0} );
        int len =0;
        
        while(Q.size()){
            
            len ++;
            auto node  = Q.front(); Q.pop();
            
            int x = node.first;
            int y = node.second;
            
            if(x==R-1 && y==C-1)
                return dist[x][y];
            
            vector< vector<int> > dir { {-1, -1}, {-1, 0}, {-1, 1},
                                            {0, -1}, {0, 1},
                                       {1, -1}, {1, 0}, {1, 1}};
            
            
            for(int i=0; i<8; i++){
                
                int xx = x+dir[i][0];
                int yy = y+dir[i][1];
                
                
                if(0 <= xx && xx<R && 0<=yy && yy<C && grid[xx][yy] ==0 && dist[x][y]+1 <dist[xx][yy]){
                    
                    dist[xx][yy] = dist[x][y]+1;
                    
                    //cout<<xx<<" "<<yy<<endl;
                    
                    if(xx==R-1 && yy==C-1)
                        return dist[xx][yy];
                    
                    Q.push({xx, yy});
                }
                
            }
            
        }//while
        
        //if(dist[R-1][C-1]==1e9)
            return -1;

    }
};