class Solution {
public:
    
        int dfs(int i, vector<vector<int>> &graph, vector<int> &isSafe){
        
            //if already decided
        if(isSafe[i] != -1) return isSafe[i];
        
        isSafe[i] = 2;  //consider it unsafe
        
        for(int node : graph[i]){
            
            if(dfs(node, graph, isSafe)==2){
                return 2;
            }
            
        }
        
        //if its not unsafe, its safe
        return isSafe[i] =1;
        
        
    }
    
    vector<int> method1(vector<vector<int>>& graph){
        
        int N = graph.size();
        
        vector<int> isSafe(N, -1);
        vector<int> safe;
        
        /* -1 not decided
            1 - safe
            2- unsafe
        */
        
        for(int i=0; i<N; i++){
            
            if(dfs(i, graph, isSafe)==1){
                safe.push_back(i);        
            }
            
        }
        
        return safe;
        
    }
    
    //check if this node is involved in a Loop
    bool dfsCheck(int node, vector<vector<int>> &adj, vector<bool> &visited, vector<bool> &currentPath, vector<bool> &safe) {
		
        	visited[node] = true;
	        currentPath[node] = true;
          safe[node] = false;


        for(int neigh: adj[node]){

            if(visited[neigh]==true){
                //loop
                if(currentPath[neigh]==true){
                    //not a teminal Node
                    safe[node] = false;
                    return true;
                }
                
            }else{
                //loop
                if(dfsCheck(neigh, adj, visited, currentPath, safe)){
                    safe[node] = false;
                    return true;
                }
            }

        }//for

	currentPath[node] = false;
    safe[node] = true;
	return false;
	}
    
    vector<int> method2(vector<vector<int>>& graph){
     
        int N = graph.size();
        
    
        vector<bool> visited(N, false);
		vector<bool> currentPath(N, false);
		vector<bool> safe(N, false);    //1-safe node, 0-unsafe
        
		vector<int> safeNodes;
        
		for (int i = 0; i < N; i++) {
			if (!visited[i]) {
				dfsCheck(i, graph, visited, currentPath, safe);
                
                
			}
		}
        
        for (int i = 0; i < N; i++) {
			if (safe[i] == true)
                safeNodes.push_back(i);
		}
		
        
        return safeNodes;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        /*  Directed Graph
            Safe Node - If every path from that node leads to a Terminal Node
            Terminal Node - has no outgoing edges
            
            
            Approach 1: 
            Consider every node as Unsafe Node by default,
            untill you find it is a terminal Node.
            
            mark a node as unsafe,
            visite its neighbour ,
            if any of the neighour returns unsafe, (happen only whne there is a cycle and it revisites again
            return this node as unsafe
            
            other wise return this node as safe
        */
        
        //return method1(graph);
        
        /*
        Approach2:
        
        Check for cycles
        
        If a node is involved in cycle,
        it is unsafe,
        
        If its not involved in cyle it is Safe.
        */
        
        return method2(graph);
    }
    
    
};