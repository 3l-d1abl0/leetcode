// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    
        void solve(int x, int y, vector<vector<int>> &maze, int N, string &path, vector<vector<int>> &dir, vector<string> &ans, vector<vector<bool>> &visited)
    {

        // cout << x << ", " << y << endl;
        if (x == N - 1 && y == N - 1)
        {
           // cout << "returning" << x << " " << y << N << endl;
            ans.push_back(path);
            return;
        }
        visited[x][y] = true;
        // cout << path << endl;
        //  DLRU
        string dirName = "DLRU";
        for (int i = 0; i < dirName.size(); i++)
        {

            int xx = x + dir[i][0], yy = y + dir[i][1];
            if (xx >= 0 && xx < N && yy >= 0 && yy < N && visited[xx][yy] == false && maze[xx][yy] == 1)
            {
                path.push_back(dirName[i]);
                solve(xx, yy, maze, N, path, dir, ans, visited);
                path.pop_back();
                visited[xx][yy] = false;
            }
        }
    }
    
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        
        vector<string> ans;
        if (m[0][0] == 0 || m[n - 1][n - 1] == 0)
            return ans;

        vector<vector<bool>> visited(n + 1, vector<bool>(n + 1, false));
        int x = 0, y = 0;
        string path;
        vector<vector<int>> dir{{1, 0}, {0, -1}, {0, 1}, {-1, 0}};

        solve(x, y, m, n, path, dir, ans, visited);

        return ans;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends