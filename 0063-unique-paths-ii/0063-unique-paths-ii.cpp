class Solution {
public:
    
    
    int recMemo(int i, int j, vector<vector<int>> &maze, vector<vector<int>> &dp) {
        
        if (i < 0 || j < 0) return 0; // If we go out of bounds, return 0
        if (i == 0 && j == 0)
            return maze[i][j] == 0; // If we reach the destination (0, 0), return 1
        
        // Base cases
        if (i >= 0 && j >=0 && maze[i][j] == 1) return 0; // If there's an obstacle at (i, j), return 0
        
        
        if (dp[i][j] != -1)
            return dp[i][j]; // If the result is already computed, return it

        // Recursive calls to explore paths from (i, j) to (0, 0)
        int up = recMemo(i - 1, j, maze, dp);
        int left = recMemo(i, j - 1, maze, dp);

        // Store the result in the DP table and return it
        return dp[i][j] = up + left;
    }
    
    
    int recursive(vector<vector<int>> &maze) {
        
        int n = maze.size();
        int m = maze[0].size();
        
        vector<vector<int>> memo(n, vector<int>(m, -1)); 
        return recMemo(n - 1, m - 1, maze, memo); // Start from the bottom-right corner
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        return recursive(obstacleGrid);      
        
    }
};