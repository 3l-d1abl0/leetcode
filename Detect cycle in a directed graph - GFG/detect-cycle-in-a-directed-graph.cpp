//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    
    bool dfs(int i, vector<bool> &visited, vector<bool> &dfspath, vector<int> adj[]){
        
        visited[i] = true;
        dfspath[i] = true;
        
        for(int node : adj[i]){
            
            if(visited[node]== false){
                if(dfs(node, visited, dfspath, adj)==true)
                    return true;
            }else{
                if(dfspath[node]==true)
                    return true;
            }
        }
        
        
        dfspath[i] = false;
        return false;
        
    }
    
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        
        
        vector<bool> visited(V, false);
        vector<bool> dfsPath(V, false);
        
        
        for(int i=0; i<V; i++){
            
            if(visited[i]==false){
                
                if(dfs(i, visited, dfsPath, adj)==true)
                    return true;
            }
        }
        
        return false;
    }//bool
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends