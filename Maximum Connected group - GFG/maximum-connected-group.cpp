//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
class Solution {
  public:
  
        const int DIR[5] = {0, 1, 0, -1, 0};
    int m, n;
    unordered_map<int, int> componentSize;
  
    int MaxConnection(vector<vector<int>>& grid) {
        // code here
        
        m = grid.size(); n = grid[0].size();
        int ans = 0, nextColor = 2;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] != 1) continue; // Only paint when it's an island cell
                paint(grid, r, c, nextColor++);
                ans = max(ans, componentSize[nextColor - 1]);
            }
        }
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] != 0) continue; // Skip non-empty cell
                unordered_set<int> neighborColors;
                for (int i = 0; i < 4; ++i) {
                    int nr = r + DIR[i], nc = c + DIR[i+1];
                    if (nr < 0 || nr == m || nc < 0 || nc == n || grid[nr][nc] == 0) continue;
                    neighborColors.insert(grid[nr][nc]);
                }
                int sizeFormed = 1;
                for (int color : neighborColors) sizeFormed += componentSize[color];
                ans = max(ans, sizeFormed);
            }
        }
        return ans;
    }
    
        void paint(vector<vector<int>>& grid, int r, int c, int color) {
        if (r < 0 || r == m || c < 0 || c == n || grid[r][c] != 1) return;
        grid[r][c] = color;
        componentSize[color] += 1;
        for (int i = 0; i < 4; ++i) paint(grid, r + DIR[i], c + DIR[i+1], color);
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        Solution obj;
        cout<<obj.MaxConnection(grid)<<"\n";
    }
}

// } Driver Code Ends