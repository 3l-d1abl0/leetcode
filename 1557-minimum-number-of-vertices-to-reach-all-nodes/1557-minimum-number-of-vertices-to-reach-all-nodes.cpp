
class Solution {
public:
    
    vector<int> method1(int N, vector<vector<int>>& edges){
        
        /*
            Start traversal from every node that is unvisited.
            The nodes which remains unvisited are the one.
        */
        
        vector<int> ans;
        vector<vector<int>> adj(N);
        
        for (int i = 0; i < edges.size(); i++) {
            //from -> to
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        
        
        //Start BFS traversal from each Node
        queue<int> q;
        vector<bool> visited(N, false);
        
        for (int i = 0; i < N; i++) {
            
            //already visited
            if (visited[i])
                continue;
            
            //Strart BFS traversal from this Node
            q.push(i);
            
            
            //BFS
            while (!q.empty()) {
                
                int node = q.front(); q.pop();
                
                //visit all the neighbouring nodes and make it visited
                for (int neighbour : adj[node]) {
                    
                    //already visited, no need to visit
                    if (visited[neighbour])
                        continue;
                    
                    visited[neighbour] = true;
                    q.push(neighbour);
                }//for
                
            }//while
            
        }//for
 
        //check the ones couldn't be visted
        for (int i = 0; i < N; i++) {
            if (!visited[i]) {
                ans.push_back(i);
            }
        }
        
        return ans;
        
    }
    
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        
        //1. Method1 : visit nodes
        return method1(n, edges);
        
    }
};
