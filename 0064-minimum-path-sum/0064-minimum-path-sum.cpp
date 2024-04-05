class Solution {
public:
    
    int recMemo(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &memo){
        
        if(row<0 || col <0)
            return INT_MAX;
        
        if(row==0 && col==0)
            return grid[row][col];
        
        if(memo[row][col]!=-1)
            return memo[row][col];
        
        int up=INT_MAX;
        int left = INT_MAX;
        if(row-1>=0)
            up = recMemo(row-1, col, grid, memo);
        
        if(col-1>=0)
            left = recMemo(row, col-1, grid, memo);
        
        
        return memo[row][col] = min(up, left)+grid[row][col];
        
    }
    
    int bottomUp(vector<vector<int>> &grid){
        
        int M = grid.size();    //row
        int N = grid[0].size();    //col
        
        vector<vector<int>> dp(M, vector<int>(N, INT_MAX));
        
        for(int i=0; i<M; i++){
            for(int j=0; j<N; j++){
                
        
                if(i==0 && j==0){
                    dp[i][j] = grid[0][0];
                    continue;
                }

                int up=INT_MAX;
                int left = INT_MAX;
                if(i-1>=0)
                    up = dp[i-1][j];

                if(j-1>=0)
                    left = dp[i][j-1];


                dp[i][j] = min(up, left)+grid[i][j];
                
            }
        }//for i
        
        return dp[M-1][N-1];
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        
        //1. Recursion+Memo
        //int M = grid.size();    //row
        //int N = grid[0].size();    //col
        
        //vector<vector<int>> memo(M, vector<int>(N, -1));
        //return recMemo(M-1, N-1, grid, memo);
        
        
        return bottomUp(grid);
    }
};