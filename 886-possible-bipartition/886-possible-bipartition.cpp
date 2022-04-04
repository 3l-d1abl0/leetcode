class Solution {
public:
    
    bool dfs(int src, vector<int> &status, vector<vector<int>> &adj){
        
        //cout<<"col:"<<src<<" "<<status[src]<<endl;
        for(int node=0; node<adj[src].size(); node++){
            
            if(status[adj[src][node]]==-1){
                status[adj[src][node]] = 1-status[src];
                    if(dfs(adj[src][node], status, adj)==false)
                        return false;
                
            }else{
                if(status[adj[src][node]]== status[src])
                    return false;
            }
        }
      //  cout<<"T"<<src<<endl;
        return true;
    }
    
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        
        
        vector<int> status(N+1,-1);
        
        vector<vector<int>> adj(N+1);
        
        
        for(auto row: dislikes){
            adj[row[0]].push_back(row[1]);
            adj[row[1]].push_back(row[0]);
            
            
        }
        
        
        for(int i=1; i<=N; i++){
            
            if(status[i]==-1){
                
                status[i] =0;
                if(dfs(i, status, adj)==false)
                    return false;
            }
        }
        
        //cout<<"TT"<<endl;
        return true;
    }
};