class Solution {
public:
    
    vector<int> toplogicalSort(int k, vector<vector<int>>& rowConditions){
        
        vector<int> ts;
        
        unordered_map<int, vector<int>> mp;
        vector<vector<bool>> adj(k, vector<bool>(k, false));
        
        vector<int> indegree(k, 0);
        
        for(auto row: rowConditions){
            
            int x = row[0]-1;
            int y = row[1]-1;
            
            if(adj[x][y]==true)
                continue;
            
            adj[x][y]=true;
            
            indegree[y]++;
            
            mp[x].push_back(y);
        }
        
        queue<int> q;
        
        
        for(int i=0; i<indegree.size(); i++){
            if(indegree[i]==0){
                q.push(i);
                ts.push_back(i);    
            }
            
        }
        
        
        while(!q.empty()){
            
            int node = q.front(); q.pop();
            
            for(int v: mp[node]){
                indegree[v]--;
                
                if(indegree[v]==0){
                    q.push(v);
                    ts.push_back(v);
                }
            }
            
        }
        
        
        return ts;
    }
    
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        
        vector<int> rowOrder = toplogicalSort(k, rowConditions);
        if(rowOrder.size()!=k) return {};
        /*for(int ele: rowOrder)
            cout<<ele<<" ";
        cout<<endl;*/
        
        vector<int> colOrder = toplogicalSort(k, colConditions);
        if(colOrder.size()!=k) return {};
        /*for(int ele: colOrder)
            cout<<ele<<" ";
        cout<<endl;*/
        
        
        unordered_map<int, int> rMapping;
        for(int i=0; i<rowOrder.size(); i++){
            rMapping[rowOrder[i]+1] = i;
        }
        
        
        vector<vector<int>> ans(k, vector<int>(k,0));
        
        for(int i=0; i<colOrder.size(); i++){
            
            ans[rMapping[colOrder[i]+1]][i] = colOrder[i]+1;
        }
        
        
        
        
        return ans;
    }
};