class Solution {
public:
    
    void DFS(int src, vector<vector<int>> &adj, stack<int> &st, vector<bool> &vis){
        
        
        vis[src] = true;
        
        //Process the dependent courses
        for(int node: adj[src]){
            
            if(!vis[node]){
                DFS(node, adj, st, vis);
            }
            
        }
        
        
        st.push(src);
        
    }
    
    vector<int> findOrder(int N, vector<vector<int>>& pre) {
     
        
        vector<vector<int>> adj(N);
        
        for(auto ele: pre){
            adj[ele[1]].push_back(ele[0]);
            
        }
        
        
        stack<int> st;
        vector<bool> vis(N);
        
        
        for(int i=0; i<N; i++){
            if(!vis[i]) 
                DFS(i, adj, st, vis);
        }
        
        
        return cyclic(st, adj, N);
    }
    
    vector<int> cyclic(stack<int> &st, vector<vector<int>> &adj, int n){
        
        	unordered_map<int, int> pos;
	        int index = 0;
        
            vector<int> topo;
        
        
            while(!st.empty()){
                
                pos[st.top()] = index;
                
                topo.push_back(st.top());
                
                st.pop();
                
                index++;
                
            }
        
        
            
        for(int par=0; par<n; par++){
            
            for(int node: adj[par]){
                if(pos[par]> pos[node])
                    return vector<int> {};
            }
            
        }
        
        
        //not a cycle
        return topo;
        
        
    }
    
};