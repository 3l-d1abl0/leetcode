class Solution {
public:
    int numOfMinutes(int N, int headID, vector<int>& manager, vector<int>& informTime) {
        
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
};