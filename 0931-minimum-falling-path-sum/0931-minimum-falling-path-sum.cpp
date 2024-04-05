class Solution {
public:
    
    int recMemo(int row, int col, vector<vector<int>> &matrix, vector<vector<int>> &memo){
        
        if(row<0 || col <0 || col >=matrix[0].size())
            return 1e7;
        //base
        if(row==0)
            return matrix[0][col];
        
        if(memo[row][col]!=-1)
            return memo[row][col];
        
        int min_path_sum = 1e7;
        for(int i=-1; i<=1; i++){
            
            min_path_sum = min(min_path_sum, recMemo(row-1, col+i, matrix, memo));
        }
        
        
        return memo[row][col] = min_path_sum+matrix[row][col];
    }
    
    int bottomUp(vector<vector<int>>& matrix) {
        
        int n = matrix.size(); // Number of rows in the matrix
        int m = matrix[0].size(); // Number of columns in the matrix

        // Create a 2D DP (dynamic programming) array to store maximum path sums
        vector<vector<int>> dp(n, vector<int>(m, 1e7));

        // Initialize the first row of dp with values from the matrix (base condition)
        for (int j = 0; j < m; j++) {
            dp[0][j] = matrix[0][j];
        }

        // Iterate through the matrix rows starting from the second row
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // Calculate the maximum path sum for the current cell considering three possible directions: up, left diagonal, and right diagonal

                // Up direction
                int up = matrix[i][j] + dp[i - 1][j];

                // Left diagonal direction (if it's a valid move)
                int leftDiagonal = matrix[i][j];
                if (j - 1 >= 0) {
                    leftDiagonal += dp[i - 1][j - 1];
                } else {
                    leftDiagonal += 1e7; // A very large negative value to represent an invalid path
                }

                // Right diagonal direction (if it's a valid move)
                int rightDiagonal = matrix[i][j];
                if (j + 1 < m) {
                    rightDiagonal += dp[i - 1][j + 1];
                } else {
                    rightDiagonal += 1e7; // A very large negative value to represent an invalid path
                }

                // Store the maximum of the three paths in dp
                dp[i][j] = min(up, min(leftDiagonal, rightDiagonal));
            }
        }

        // Find the maximum value in the last row of dp, which represents the maximum path sums ending at each cell
        int minn = 1e7;
        for (int j = 0; j < m; j++) {
            minn = min(minn, dp[n - 1][j]);
        }

        // The maximum path sum is the maximum value in the last row
        return minn;
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        
        /*1. Recursion+memoizariont
            Start from every point of last row,
            if you reach to the first row return
        
        */
        
        /*
        int N = matrix.size();
        int M = matrix[0].size();
        
        vector<vector<int>> memo(N, vector<int> (M, -1));
        
        int min_path_sum = INT_MAX;
        for(int i=0; i<M; i++){
            
            min_path_sum = min(min_path_sum, recMemo(N-1, i, matrix, memo));
        }
        
        return min_path_sum;
        */
        
        //2. Bottom Up
        return bottomUp(matrix);
    }
};