class Solution {
    int timer = 1;
public:

    //dfs(-1, 0, adj, vis, time, low, bridges);
    void dfs(int parent, int node, vector<vector<int>>&adj, vector<bool>&vis, vector<int>&discoveryTime, vector<int>&low, vector<vector<int>>&bridges){
        
        vis[node]=true;
        discoveryTime[node]=low[node]=timer;
        timer++;

        for(auto neighbour:adj[node]){
            
            if(neighbour==parent) continue; //skip
            if(!vis[neighbour]){//if neighbour not visted, visit it 

                dfs(node, neighbour, adj, vis, discoveryTime, low, bridges);
                
                low[node]=min(low[node], low[neighbour]);
                if(low[neighbour]>discoveryTime[node])
                    bridges.push_back({neighbour, node});
            }else{
                /* If already visited , update the current 'low'
                */
                low[node]=min(low[node], low[neighbour]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        
        vector<vector<int>> adjList(n);
        for(auto edge:connections){
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }

        vector<bool> vis(n, 0);
        vector<int> discoveryTime(n,0);
        vector<int> low(n,0);//low time-node reachable
        vector<vector<int>> bridges;

        dfs(-1, 0, adjList, vis, discoveryTime, low, bridges);
        return bridges;
    }
};