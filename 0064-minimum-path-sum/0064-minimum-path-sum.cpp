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
    
    int minPathSum(vector<vector<int>>& grid) {
        
        //1. Recursion+Memo
        int M = grid.size();    //row
        int N = grid[0].size();    //col
        
        vector<vector<int>> memo(M, vector<int>(N, -1));
        return recMemo(M-1, N-1, grid, memo);
    }
};