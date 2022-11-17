class Solution {
public:
    bool canFinish(int N, vector<vector<int>>& prerequisites) {    
        return dfs(N, prerequisites);
    }
    
    bool dfs(int N, vector<vector<int>> &prerequisites){
        
        vector<vector<int>>adj(N);
	
        for(int i=0; i<prerequisites.size(); i++){

            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);

        }


        vector<bool> visited(N, false);
        vector<bool> dfsPath(N, false);


        for(int i=0; i<N; i++){

            if(!visited[i]){
                if(cyclicDFS(i, visited, dfsPath, adj))
                    return false;
            }


        }
	
	
	    return true;
        
    }
    
    
    bool cyclicDFS(int src, vector<bool> &visited, vector<bool> &dfsPath, vector<vector<int>> &adjList){
	
	visited[src] = true;
	dfsPath[src] = true;
	
	
	for(int node: adjList[src]){
		
		if(visited[node]==true){
			if(dfsPath[node]==true)
				return true;
		}else{
			if(cyclicDFS(node, visited, dfsPath, adjList))
				return true;
		}
		
	}
	
	dfsPath[src] = 0;
	return false;
	
}
};