class Solution {
public:
    
    int method1(int N, int headID, vector<int>& manager, vector<int>& informTime) {
        
        vector<vector<int>> adj(N);
        
        for(int emp=0; emp<manager.size(); emp++){
            
            if(manager[emp] == -1)
                continue;
            
            adj[manager[emp]].push_back(emp);
            
        }
        
        queue<pair<int, int> > q;
        
        //emp, time taken to reach that empl
        q.push({headID, 0});
        
        int maxTime = -1;
        while(!q.empty()){
            
            auto pp = q.front(); q.pop();
            int node = pp.first;
            int timeTaken = pp.second;
            
            maxTime = max(maxTime, timeTaken);
            
            for(int neigh: adj[node]){
                
                q.push({neigh, timeTaken+informTime[node]});
            }
            
        }//while
        
        
        return maxTime;
        
    }
    
    int method2(int N, int headID, vector<int>& manager, vector<int>& informTime) {
        
        vector<vector<int>> adj(N);
        for(int empl=0; empl<manager.size(); empl++){
            if(manager[empl]==-1)
                continue;
            
            adj[manager[empl]].push_back(empl);
        }
        
        return dfs(headID, informTime, adj);
        
        
    }
    
    int dfs(int node, vector<int>& informTime, vector<vector<int>> &adj){
        
        int ans =0;
        
        for(int neigh: adj[node]){
            
            ans = max(ans,dfs( neigh, informTime, adj) );
        }
        
        
        return ans+ informTime[node];
    }
    
    
    int numOfMinutes(int N, int headID, vector<int>& manager, vector<int>& informTime) {
        
        
        //1. Method1: BFS
        //return method1(N, headID, manager, informTime);
        
        
        //2. Method2: DFS
        return method2(N, headID, manager, informTime);
        
    }
};