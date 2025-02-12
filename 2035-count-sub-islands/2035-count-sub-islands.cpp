class Solution {
public:
    
    int dir[5] = {-1, 0, 1, 0,-1};
    
    pair<int, int> dfs(vector<vector<int>>& g1, vector<vector<int>>& g2, int i, int j) {
        
        if (i < 0 || j < 0 || i >= g1.size() || j >= g1[0].size() || g2[i][j] == 0)
            return {0, 0};
        
        //create count of current node
        pair<int, int> res{g1[i][j], g2[i][j]};
        g2[i][j] = 0;//reset current g2 cell as 0

        for (int d = 0; d < 4; ++d) {
            auto [cnt1, cnt2] = dfs(g1, g2, i + dir[d], j + dir[d + 1]);
            res.first += cnt1;
            res.second += cnt2;
        }
        return res;
    }
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        /*
        Time Complexity: O(R×C)
        Space Complexity: O(R×C)
        
        */
        int R = grid1.size();
        int C = grid1[0].size(), res = 0;
        
        for (int i = 0; i < R; ++i)
            for (int j = 0; j < C; ++j) {
                
                if(grid2[i][j]==1){
                    auto [cnt1, cnt2] = dfs(grid1, grid2, i, j);
                    res += cnt1 > 0 && cnt1 == cnt2;
                }
            }
        
        return res;
        
    }
};