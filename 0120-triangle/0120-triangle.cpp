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
    
    int minimumTotal(vector<vector<int>>& triangle) {
        
        //1. Recursion+Memoization
        
        int N = triangle.size();
        
         vector<vector<int> > memo(N, vector<int>(N, -1));
        return recMemo(0, 0, triangle, N, memo);
        
    }
};