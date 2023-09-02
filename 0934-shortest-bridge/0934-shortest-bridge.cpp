class Solution {
public:
    
    pair<int, int> getLandCoOrdinate(vector<vector<int>> &grid){
        
        int R = grid.size();
        int C = grid[0].size();
        
        for(int i=0; i<R; i++){
            
            for(int j=0; j<C; j++){
                if(grid[i][j]==1)
                    return make_pair(i, j);
            }
        }
        
        
        return {-1, -1};
    }
    
    
    void dfsMakeIt2(int x, int y, vector<vector<int>> &grid, queue<pair<int, int>> &q){
        
        int N = grid.size();
        
        grid[x][y]=2;   //make it 2
        q.push({x, y});
        
        vector<vector<int>> dir { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
        
        for(auto row: dir){
            
            int new_x = x+row[0];
            int new_y = y+row[1];
            
            if(0<=new_x && new_x<N && 0<=new_y && new_y<N){ //within limits of boundary
                
                if(grid[new_x][new_y]==1)
                    dfsMakeIt2(new_x, new_y, grid, q);
                
            }
        }
        
    }
    
    
    int travelWaters(vector<vector<int>> &grid, queue< pair<int, int> > &q){
        
        
        int N = grid.size();
        
        int dist =0;
        
        vector<vector<int>> dir { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
        
        while(!q.empty()){
            
            int sz= q.size();
            
            //cout<<"lvl "<<dist<<" : "<<sz<<" nodes"<<endl;
            for(int i=0; i<sz; i++){
                
                auto [x, y] = q.front();
                q.pop();
                
             
               for(auto row: dir){

                    int new_x = x+row[0];
                    int new_y = y+row[1];

                    if(0<=new_x && new_x<N && 0<=new_y && new_y<N){ //within limits of boundary


                        if(grid[new_x][new_y]==1)
                            return dist;
                        
                        if(grid[new_x][new_y]==0){
                            grid[new_x][new_y] = -1; //water is visited
                        
                            q.push({new_x, new_y});
                            
                        }

                    }
                }//for dir       
                
                
            }//for sz
            
            dist++;
            
        }//while
        
        
        return -1;
    }
    
    int shortestBridge(vector<vector<int>>& grid) {
        
        
        //1. Find one Island, make its value 2 to differentiate
        
        
        pair<int, int> xy = getLandCoOrdinate(grid);
        
        if(xy.first==-1 || xy.second==-1)
            return -1;//ERR
        
        
        //cout<<xy.first<<" "<<xy.second<<endl;
        
        queue<pair<int, int>> q;
        dfsMakeIt2(xy.first, xy.second, grid, q);
        
        //printGrid(grid);
        
        //2. Start Bfs from each cell and check the min distance to reach each cell
        // If you reached land (1) , get the dist
        
        //q currently contains all land cells with val 2
        
        return travelWaters(grid, q);

    }
    
    void printGrid(vector<vector<int>> &grid){
        
        
        for(auto row: grid){
            
            for(int ele: row){
                    
                cout<<ele<<" ";
            }
            
            cout<<endl;
        }
    }
};