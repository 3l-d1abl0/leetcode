class Solution {
public:
    
    int recMemo(int i, int j, vector<vector<int>>& memo) {
        // Base case: If we reach the top-left corner (0, 0), there is one way.
        if (i == 0 && j == 0)
            return 1;

        // If we go out of bounds or reach a blocked cell, there are no ways.
        if (i < 0 || j < 0)
            return 0;

        // If we have already computed the number of ways for this cell, return it.
        if (memo[i][j] != -1)
            return memo[i][j];

        // Calculate the number of ways by moving up and left recursively.
        int up = recMemo(i - 1, j, memo);
        int left = recMemo(i, j - 1, memo);

        // Store the result in the dp table and return it.
        return memo[i][j] = up + left;
    }
    
    int bottomUp(int m, int n) {
        
        vector<vector<int>> dp (m, vector<int> (n, 0));
        
        //base
        dp[0][0] =1;
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                
                if(i==0 && j==0){
                    dp[i][j]=1;
                    continue;
                }
                
                int up =0;
                if(i-1>=0)
                    up = dp[i-1][j];
                
                int left =0;
                if(j-1>=0)
                    left = dp[i][j-1];
                
                dp[i][j] = up+left;
            }
        }
        
        //print(dp);
        return dp[m-1][n-1];
        
    }
    
    
    int opti(int m, int n) {
        
        vector<int> prev(n, 0);

        for (int i = 0; i < m; i++) {

            //current row
            vector<int> temp(n, 0);
            for (int j = 0; j < n; j++) {
                
                
                if (i == 0 && j == 0) {
                    temp[j] = 1;
                    continue;
                }

                int up = 0;
                int left = 0;

                if (i > 0)
                    up = prev[j];

                if (j > 0)
                    left = temp[j - 1];
                temp[j] = up + left;
            }

            prev = temp;
        }

        return prev[n - 1];
    }
    
    int uniquePaths(int m, int n) {
     
        //vector<vector<int>> dp(m, vector<int>(n, -1));

        //1. Call the utility function with the bottom-right cell as the starting point.
        //return recMemo(m - 1, n - 1, dp);
        
        //2. Tabulation
        //return bottomUp(m, n);
        
        //3. opti
        return opti(m, n);
    }
};