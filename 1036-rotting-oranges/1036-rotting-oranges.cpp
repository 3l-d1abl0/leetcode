class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int N = grid.size();
        int M = grid[0].size();
        
        queue<pair<int,pair<int, int>>> q;
        
        int mango=0;
        
        for(int i=0; i<N; i++){
                
            for(int j=0; j<M; j++){
                if(grid[i][j]==2){
                    q.push({0, {i,j}});
                }
                
                if(grid[i][j]!=0){
                    mango++;
                }
            }
            
        }
        
        int max_time = 0;
        int mango_processed =0;

        //OR a for loop for the sie of queue
        while(!q.empty()){
            
            auto node = q.front();
            q.pop();
            
            mango_processed++;
            
            vector<vector<int>> dir {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
            int time = node.first;
            max_time = max(max_time, time);
            int row= node.second.first;
            int col= node.second.second;
            
            for(int i=0; i<4; i++){
                
                int new_row = row+dir[i][0];
                int new_col = col+dir[i][1];
                
                if(new_row<0 || new_row>=N || new_col<0 || new_col>=M || grid[new_row][new_col]==0 || grid[new_row][new_col]==2)
                    continue;
                
                q.push({time+1, {new_row, new_col}});
                grid[new_row][new_col]= 2;
                
            }
            
            
        }
        
        
        
        if(mango==mango_processed){
            return max_time;
        }else{
            return -1;
        }
    }
};