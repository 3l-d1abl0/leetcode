class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        queue< pair< pair<int, int>, int> > q;
        
        int R = mat.size();
        int C = mat[0].size();
        
        vector<vector<int>> ans(R, vector<int>(C, 0));
        vector<vector<bool>> vis(R, vector<bool>(C, false));
        
        
        for(int i=0; i<R; i++){
            
            for(int j=0; j<C; j++){
                
                if(mat[i][j] ==0){
                    q.push( {{i, j}, 0} );
                    vis[i][j] = true;
                }
                
            }//j
            
        }//i
        
        
        
        
        while(!q.empty()){
            
            pair< pair<int, int>, int> node = q.front();
            q.pop();
            
            int row = node.first.first;
            int col = node.first.second;
            
            
            int dist = node.second;
            
            
            vector<int> xx({-1, 0, 1, 0});
            vector<int> yy({ 0, +1, 0, -1});
            
            ans[row][col] = dist;
            
            for(int i=0; i<4; i++){
                
                int newRow = row+xx[i];
                int newCol = col+yy[i];
                
                if(0 <= newRow && newRow <R && 0<= newCol && newCol <C && vis[newRow][newCol] ==false){
                    q.push({ { newRow, newCol }, dist+1});
                    vis[newRow][newCol] = true;
                }
            }
        }
        
        
        return ans;
    }
};