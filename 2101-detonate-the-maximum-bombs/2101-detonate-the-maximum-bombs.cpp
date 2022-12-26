class Solution {
public:
    
    
    int bfs(int node, vector<int> &vis, vector<vector<int>> &adj){
        
        
        queue<int> q;
        vis[node] = true;
        
        q.push(node);
        
        int nodeCount =1;
        
        while(!q.empty()){
            
            int n = q.front(); q.pop();
            
            for(int nn: adj[n]){
               
                if(vis[nn]==false){
                    vis[nn] = true;
                    q.push(nn);
                    nodeCount++;
                }
            }
            
        }
        
        return nodeCount;
        
    }
    
    int maximumDetonation(vector<vector<int>>& bombs) {
        
        // (x1 - x)^2 + (x1 - y)^2 <= r^2   Inside
        
        //Compute Graph
        int N = bombs.size();
        
        vector<vector<int>> adj(N);
        
        
        for(int i=0; i<N; i++){
            
            for(int j=0; j<N; j++){
                
                if(i==j)
                    continue;

                    //i as center
                if( pow(bombs[j][0] - (bombs[i][0]), 2) + pow(bombs[j][1] - (bombs[i][1]), 2) <= pow(bombs[i][2], 2)){

                    adj[i].push_back(j);    //j falls under i
                    //cout<<i<<" -> "<<j<<endl;
                    //adj[j].push_back(i);


                }
            
            }
        }//i
        
        
        int ans = 0;
        
        for(int i=0; i<N; i++){
            
            vector<int> vis(N , false);
            
            if(vis[i]==false)
                ans = max(ans, bfs(i, vis, adj));
        }
        
        
        return ans;
    }
};