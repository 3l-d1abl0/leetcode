class Solution {
public:
    double solve(vector<vector<double>> adj, int &src, int &dst, vector<int>& vis) {
        if (src == dst) return 1.0;
        double a = -1;
        for (int i = 0; i < adj[src].size(); i++) {
            if (adj[src][i] > 0 && vis[i] == 0) {
                vis[i] = 1;
                a = adj[src][i] * solve(adj, i, dst, vis);
                vis[i] = 0;
                if (a > 0) return a;
            }
        }
        return -1;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, int> m;
        vector<double> ans;
        int id = 0, src, dst;

        // Assigning unique IDs to variables
        for (auto i : equations) {
            for (auto j : i) if (m.find(j) == m.end()) m[j] = id++;
        }

        // Initializing adjacency matrix
        vector<vector<double>> adj(m.size(), vector<double>(m.size(), -1));
        vector<int> vis(m.size(), 0);
        id = 0;

        // Filling adjacency matrix with given equations
        for (auto i : equations) {
            adj[m[i[0]]][m[i[1]]] = values[id];
            adj[m[i[1]]][m[i[0]]] = 1.0 / values[id];
            adj[m[i[0]]][m[i[0]]] = 1, adj[m[i[1]]][m[i[1]]] = 1;
            id++;
        }

        // Processing queries
        for (auto i : queries) {            
            if (m.find(i[0]) != m.end() && m.find(i[1]) != m.end()) {
                if (adj[m[i[0]]][m[i[1]]] != -1) 
                    ans.push_back(adj[m[i[0]]][m[i[1]]]);
                else {
                    fill(vis.begin(), vis.end(), 0);
                    src = m[i[0]], dst = m[i[1]];
                    ans.push_back(solve(adj, src, dst, vis));
                }
            } else ans.push_back(-1);
        }
        return ans;
    }
};