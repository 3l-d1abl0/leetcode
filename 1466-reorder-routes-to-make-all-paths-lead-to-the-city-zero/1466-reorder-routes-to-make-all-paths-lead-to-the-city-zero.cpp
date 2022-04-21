class Solution {
public:
    int minReorder(int n, vector<vector<int>>& conn) {
        
        
        //make and adj
        //-ive to denote incoming edge, +ive to denote outgoing edge
        
        vector<bool> visited(n+1, false);
        
        vector<vector<int>> adj(n+1);
        
        for(auto ele: conn){
            
            int u = ele[0]+1, v= ele[1]+1;
            
            adj[u].push_back(v);    //u->v
            adj[v].push_back(-u);    //v <- -u
        }
        
        int src =1;
        int count = 0;
        dfs(src, adj, visited, count);
        cout<<endl;
        
        return count;
    }
    
    
    void dfs(int src, vector<vector<int>> &adj, vector<bool> &visited, int &count){
            
        visited[src] = true;
        cout<<src<<" "; 
        
        for(auto node: adj[src]){
            
            if(visited[abs(node)]==false){    //if not visited
                
                if(node>0)  //outgoing edge, needs to be reversed
                    count++;
                
                dfs(abs(node), adj, visited, count);
                
            }
            
            
        }
    }
};