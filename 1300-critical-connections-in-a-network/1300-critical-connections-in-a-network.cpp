class Solution {
    int timer = 1;
public:
    void dfs(int node,int parent, vector<int>&vis, vector<int>&time, vector<int>&low, vector<vector<int>>&adj, vector<vector<int>>&bridges){
        vis[node]=1;
        time[node]=low[node]=timer;
        timer++;
        for(auto it:adj[node]){
            if(it==parent) continue;
            if(!vis[it]){
                dfs(it, node, vis, time, low, adj, bridges);
                low[node]=min(low[node], low[it]);
                if(low[it]>time[node]) bridges.push_back({it, node});
            }
            else low[node]=min(low[node], low[it]);
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for(auto it:connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> vis(n, 0);
        vector<int> time(n,0);
        vector<int> low(n,0);
        vector<vector<int>> bridges;
        dfs(0, -1, vis, time, low, adj, bridges);
        return bridges;
    }
};