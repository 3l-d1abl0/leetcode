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
        
        int R= mat.size();
        int C= mat[0].size();
        
        int MAXVAL = R+C;
        vector<vector<int>> result(R, vector<int>(R, MAXVAL));
        
        
        for(int i=0;i<R; i++){
            for(int j=0; j<C; j++){
                
                if(mat[i][j]==0)
                    continue;
                
                int left=0, up=0;
                if(i-1>=0)
                    left = mat[i-1][j];
                
                if(j-1>=0)
                    up = mat[i][j-1];
                
                
                result[i][j] = min(left, up)+1;
                
            }
        }//for i
        
        
        for(int i=R-1; i>=0; i--){
            for(int j=C-1; j>=0; j--){
                
                if(mat[i][j]==0)
                    continue;
                
                int right=0, down =0;
                
                if(i+1 <=R)
                    right = mat[i+1][j];
                
                if(j+1<=C)
                    down = mat[i][j+1];
                
                
                result[i][j] += (result[i][j], min(right, down)+1);
                
            }
        }//for i
        
        
        
        return result;
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
        return method1(mat);
        
        
        /*
        Method2: DP, TC: O(M*N)
        SC: O()
        */
        //return method2(mat);
        
    }
};