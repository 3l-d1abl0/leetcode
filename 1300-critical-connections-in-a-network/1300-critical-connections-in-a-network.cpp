class Solution {
public:
    
    void dfs(int node, int parent, vector<int>adj[], vector<int>&level, vector<int>&dp,                         vector<vector<int>> &bridges){
         for(auto &c: adj[node]){
            if(level[c] == 0){
               level[c] = level[node] + 1;
               dfs(c, node, adj, level, dp, bridges);
               dp[node] += dp[c];
            }else{
                if(c != parent){
                    if(level[c] < level[node]){
                        dp[node]++;
                    }else{
                        dp[node]--;
                    }
                }
            }
         }
         if(dp[node] == 0 && level[node] > 1){
            bridges.push_back({parent, node});
         }
    }


    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
         vector<int>adj[n];
         for(auto it: connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
         }
         vector<vector<int>> bridges;
         vector<int>dp(n + 1, 0), level(n + 1, 0);
         level[0] = 1;
         dfs(0, -1, adj, level, dp, bridges);
         return bridges;
    }
};