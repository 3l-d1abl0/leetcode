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
    
    int bottomUp(vector<vector<int>> &maze) {
        
            int n = maze.size();
            int m = maze[0].size();
        
            //dp
            vector<vector<int>> dp(n, vector<int> (m, 0));
        
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    
                    //destination
                    if (i == 0 && j == 0) {
                        if (maze[i][j] == 1)//If destination is a Rock
                            return 0;
                        else
                            dp[i][j] =1;
                        
                        continue;
                    }
                    
                    
                    if(maze[i][j] == 1) {
                        dp[i][j] = 0;
                        continue;
                    }


                    int up = 0;
                    int left = 0;

                    // Check if we can move up and left (if not at the edge of the maze)
                    if (i > 0)
                        up = dp[i - 1][j];
                    
                    if (j > 0)
                        left = dp[i][j - 1];

            
                    dp[i][j] = up + left;
                }
            }

            
            return dp[n - 1][m - 1];
        }
    
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        //return recursive(obstacleGrid);      
        
        
        
        return bottomUp(obstacleGrid);
        
    }
};