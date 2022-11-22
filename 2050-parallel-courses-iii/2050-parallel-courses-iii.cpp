class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
     
        
        vector<vector<int>> adj(n+1);
        vector<int> indegree(n+1, 0);
        
        for(auto row: relations){
            
            adj[row[0]].push_back(row[1]);
            indegree[row[1]]++;    
        }
        
        queue<int> q;
        vector<int> duration(n+1, 0);
        for(int i=1; i<=n; i++){
            if(indegree[i]==0)
                q.push(i);
            
            duration[i] =time[i-1];
        }
        
        
        while(!q.empty()){
            
                int node= q.front();
                q.pop();
                
                for(int v:adj[node]){
                    indegree[v]--;
                    
                    
                    if(indegree[v]==0)
                        q.push(v);
                    
                    duration[v] = max(duration[node]+time[v-1], duration[v]);
                }
        }
            
            
            

        
        
        return *max_element(duration.begin(), duration.end());
        
        
        
    }
};