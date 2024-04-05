class Solution {
public:
    
    int recMemo(int i, int j, vector<vector<int> > &triangle, int N, vector<vector<int> > &memo) {
        
        //BASE
        if (i == N - 1)
            return triangle[i][j];
        
        if (memo[i][j] != -1)
            return memo[i][j];

        int down = recMemo(i + 1, j, triangle, N, memo);
        int diagonal = recMemo(i + 1, j + 1, triangle, N, memo);

        
        // Store the minimum of the two paths in the dp table and return it
        return memo[i][j] = min(down, diagonal) + triangle[i][j];
    }
    
    
    int bottomUp(vector<vector<int>>& triangle) {
        
        int N = triangle.size();
        
        vector<vector<int>> dp(N, vector<int> (N, INT_MAX));
        
        // Last Row is the Starting Point
        for (int j = 0; j < N; j++) {
            dp[N - 1][j] = triangle[N - 1][j];
        }

        //From Second Last row to first
        for (int i = N - 2; i >= 0; i--) {
            
            //right to left
            for (int j = i; j >= 0; j--) {
                
                // j+1 always valid
                int down =  dp[i + 1][j];
                int diagonal = dp[i + 1][j + 1];

                // Store the minimum of the two possible paths in dp
                dp[i][j] = min(down, diagonal) +triangle[i][j];
            }
        }

        // The top-left cell of dp now contains the minimum path sum
        return dp[0][0];
        
        
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        
        //1. Recursion+Memoization
        
        //int N = triangle.size();
        
        //vector<vector<int> > memo(N, vector<int>(N, -1));
        //return recMemo(0, 0, triangle, N, memo);
        
        //2. Tabulation
        return bottomUp(triangle);
        
    }
};