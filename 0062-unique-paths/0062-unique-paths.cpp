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
    
    int uniquePaths(int m, int n) {
     
        vector<vector<int>> dp(m, vector<int>(n, -1));

        // Call the utility function with the bottom-right cell as the starting point.
        return recMemo(m - 1, n - 1, dp);
        
    }
};