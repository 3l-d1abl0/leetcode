class Solution {
public:
    
    vector<vector<int>> method1(vector<vector<int>>& mat) {
        
        queue< pair<int, int> > q;
        
        int R = mat.size();
        int C = mat[0].size();
        
        vector<vector<int>> ans(R, vector<int>(C, -1));
        //vector<vector<bool>> vis(R, vector<bool>(C, false));
        
        
        for(int i=0; i<R; i++){
            
            for(int j=0; j<C; j++){
                
                //Set all 0 cell distance as Zero ans push it onto a Queue
                if(mat[i][j] ==0){
                    q.push( {i, j} );
                    ans[i][j] = 0;
                }
                
            }//j
            
        }//i
        
        
        
        
        while(!q.empty()){

            int qSize = q.size();
            //Process Level by Level
            for(int i=0; i<qSize; i++){
                
                pair<int, int> node = q.front();
                q.pop();
                
                int row = node.first;
                int col = node.second;
                
                
                int dist = node.second;
                
                
                vector<int> xx({-1, 0, 1, 0});
                vector<int> yy({ 0, +1, 0, -1});

                
                for(int i=0; i<4; i++){
                    
                    int newRow = row+xx[i];
                    int newCol = col+yy[i];
                    
                    if(0 <= newRow && newRow <R && 0<= newCol && newCol <C && ans[newRow][newCol] ==-1){
                        q.push({ newRow, newCol });
                        ans[newRow][newCol] = ans[row][col]+1;
                    }
                }
            }
        }
        
        
        return ans;
        
    }
    
    vector<vector<int>> method2(vector<vector<int>>& mat) {
        
        int m = mat.size(), n = mat[0].size(), INF = m + n; // The distance of cells is up to (M+N)
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (mat[r][c] == 0) continue;
                int top = INF, left = INF;
                if (r - 1 >= 0) top = mat[r - 1][c];
                if (c - 1 >= 0) left = mat[r][c - 1];
                mat[r][c] = min(top, left) + 1;
            }
        }
        for (int r = m - 1; r >= 0; r--) {
            for (int c = n - 1; c >= 0; c--) {
                if (mat[r][c] == 0) continue;
                int bottom = INF, right = INF;
                if (r + 1 < m) bottom = mat[r + 1][c];
                if (c + 1 < n) right = mat[r][c + 1];
                mat[r][c] = min(mat[r][c], min(bottom, right) + 1);
            }
        }
        return mat;

    }
    
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        /*
            for every cell with 1, find nearest 0
            
            Instead of going from 1 every zero, because everu zero migh get visited again
            
            go from 0 to 1,
            as soon as you find 1, keep track of the hp it took to reach there
            bfs with unit distance between each node, it will give min distance
        */
        
        //Mehthod1:BFS  TC:O(M*N)
        //SC: O(2*(M*N))
        //return method1(mat);
        
        
        /*
        Method2: DP, TC: O(M*N)
        SC: O()
        */
        return method2(mat);
        
    }
};