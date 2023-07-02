
class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> ans;
        vector<std::vector<int>> adj(n);
        
        for (int i = 0; i < edges.size(); i++) {
            int f = edges[i][0];
            int s = edges[i][1];

            adj[f].push_back(s);
        }
        
        queue<int> q;
        vector<bool> visited(n, false);
        
        for (int i = 0; i < n; i++) {
            if (visited[i]) continue;
            
            q.push(i);
            
            while (!q.empty()) {
                int rem = q.front();
                q.pop();
                
                for (int node : adj[rem]) {
                    if (visited[node]) continue;
                    visited[node] = true;
                    q.push(node);
                }
            }
        }
 
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};
