class Solution {
public:
    
    void dfs(int node, int parent, int dist, vector<int> &dis, vector<vector<int>> &adj, int &minCycle){
        
        
        dis[node] = dist;
        
        for (auto v: adj[node]) {
            
            if(v==parent)
                continue;
            //cout<<node<<"-->"<<v<<" :: "<<endl;
            if(dis[node] > dis[v]){
                //from higher end to lower end
                //cout<<dis[node]<<" "<<dis[v]<<" = "<<dis[node]-dis[v]+1<<endl;
                minCycle = min(minCycle, dis[node]-dis[v]+1);
            }else if (dis[node]+1<dis[v]){
                //v has been visted earlier with higher distance (>+1), reviste with Shorter cycle
                dfs(v, node, dist+1, dis, adj, minCycle);
            }else{
                //dis[node] == dis[v]
                //cout<<dis[node]+dis[v]+1<<endl;
            }
            
        }
        
        
    }
    
    int method1(int n, vector<vector<int>>& edges){
        
        //1. Create Adj List
        vector<vector<int>> adj(n);
        for (auto& e: edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        
        int minCycle = INT_MAX;
        
        vector<int> dis(n, INT_MAX);
        //vector<bool> visited(n, false);
        /*  Cannot apply visted logic, need to call dfs on visited nodes to 
            check for Shorter Cycles
        */
        
        
        for (int i = 0; i < n; ++i) {
            if (dis[i] == INT_MAX)
                dfs(i, -1, 0, dis, adj, minCycle);
        }
        
        return minCycle==INT_MAX? -1: minCycle;
        
    }
    
    int method2(int n, vector<vector<int>>& edges){
        
        //1. Create Adj List
        vector<vector<int>> adj(n);
        for (auto& e: edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        
        int minCycle = INT_MAX;
        vector<int> dis(n, INT_MAX);
        
        for (int i = 0; i < n; ++i) {
            
            
            dis[i] = 0;
            
            queue<int> q;
            q.push(i);
            
            while (!q.empty()) {
            
                auto node = q.front(); q.pop();
                for (auto v: adj[node]) {
                    
                    if (dis[v] == INT_MAX){
                        dis[v] = dis[node] + 1;
                        q.push(v);
                    }else if (dis[v] >= dis[node])
                        minCycle = min(minCycle, dis[v] + dis[node] + 1);
                }
            }//while
            
            fill(dis.begin(), dis.end(), INT_MAX);
        }
        
        return minCycle==INT_MAX? -1: minCycle;
    }
    
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        
        //1. DFS
        //return method1(n, edges);
        
        
        //2. BFS
        return method2(n, edges);
        
    }
};