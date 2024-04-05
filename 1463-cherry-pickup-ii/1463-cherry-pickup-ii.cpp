class Solution {
public:
    
    int recurMemo(int r, int c1, int c2, vector<vector<int>> &grid, vector<vector<vector<int>>> &memo) {
        
        if(c1 <0 || c1>= grid[0].size() || c2 <0 || c2>= grid[0].size())
            return INT_MIN;
        
        if(r == grid.size() -1){
            if (c1==c2)
                return grid[r][c1];
            else
                return grid[r][c1]+grid[r][c2];
        }
        
        
        if(memo[r][c1][c2] != -1)
            return memo[r][c1][c2];
        
        
        int maxx = INT_MIN;
        for(int d1: {-1, 0, 1}){
            for(int d2: {-1, 0, 1}){
                
                
                int ans;
                if(c1 == c2)
                    ans = grid[r][c1] + recurMemo(r+1, c1+d1, c2+d2, grid, memo);
                else
                    ans = grid[r][c1] + grid[r][c2] + recurMemo(r+1, c1+d1, c2+d2, grid, memo);
                
                
                maxx = max(maxx, ans);
            }
        }
        
        return memo[r][c1][c2] = maxx;
    }
    
    
    int bottomUp(vector<vector<int>> &grid) {
        
            int N = grid.size();
            int M = grid[0].size();
        
        
            // Create a 3D DP array to store computed results
            vector<vector<vector<int>>> dp(N, vector<vector<int>>(M, vector<int>(M, 0)));

            // base case Last Row
            for (int j1 = 0; j1 < M; j1++) {
                for (int j2 = 0; j2 < M; j2++) {
                    
                    if (j1 == j2)
                        dp[N - 1][j1][j2] = grid[N - 1][j1];
                    else
                        dp[N - 1][j1][j2] = grid[N - 1][j1] + grid[N - 1][j2];
                }
            }

            // second last row to zero
            for (int i = N - 2; i >= 0; i--) {
                
                for (int j1 = 0; j1 < M; j1++) {
                    for (int j2 = 0; j2 < M; j2++) {
                        
                        int maxx = INT_MIN;
                        
                                
                        for(int di: {-1, 0, 1}){
                            for(int dj: {-1, 0, 1}){
                        
                                if ((j1 + di < 0 || j1 + di >= M) || (j2 + dj < 0 || j2 + dj >= M))
                                    continue;
                                
                                int ans=0;

                                if (j1 == j2)
                                    ans = grid[i][j1];
                                else
                                    ans = grid[i][j1] + grid[i][j2];

                                
                                    ans += dp[i + 1][j1 + di][j2 + dj]; // Include the DP result from the next row

                                maxx = max(ans, maxx); // Update the maximum result
                            }
                        }
                        dp[i][j1][j2] = maxx; 
                    }
                }
            }//i

            //oth Row, oth cola dn M-1 col
            return dp[0][0][M - 1];
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        
        /*int N = grid.size();
        
        int M = grid[0].size();
        
        //1. Recursion + Meoization
         vector<vector<vector<int>>> memo(N, vector<vector<int>>(M, vector<int>(M, -1)));

        // Call the recursive utility function to find the maximum chocolates starting from the first row
        return recurMemo(0, 0, M - 1, grid, memo);
        */
        
        
        //2. Bottom Up 
        return bottomUp(grid);
    }
};