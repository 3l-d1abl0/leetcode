class Solution {
public:
    
    int mod = 1000000007;
    
    //vector<vector<vector<int>> memo;
    
    int paths(int i, int j, vector<vector<int>> &grid, int k, vector<vector<vector<int>>> &memo, int path){
        
        if(i>=grid.size() || j>=grid[0].size())
            return 0;
        
        if(i==grid.size()-1 && j==grid[0].size()-1){
            
            if( (path + grid[i][j])%k ==0)
                return 1;
            
            return 0;
        }
        
        if(memo[i][j][(path + grid[i][j])%k]!=-1)
            return memo[i][j][(path + grid[i][j])%k];
        
        
    int right = paths(i, j+1, grid, k, memo , path + grid[i][j]);
    int down = paths(i+1, j, grid, k, memo , path + grid[i][j]);
        
    long res = right + down;
        
    res %= mod;
    return memo[i][j][(path + grid[i][j])%k] = res;
        
    }
    
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        
        int R = grid.size();
        int C = grid[0].size();
        
        vector<vector<vector<int>>> memo(R, vector< vector<int> >(C, vector<int>(k, -1)) );
        
        return paths(0, 0, grid, k, memo , 0);
    }
};