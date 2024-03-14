class Solution {
public:
    bool canFinish(int N, vector<vector<int>>& prerequisites) {    
        
        //Method1: using DFS
        return dfs(N, prerequisites);
        
        //Method2: Using BFS
        //return bfs(N, prerequisites); //kahns Topo 16ms
    }
    
    
    bool bfs(int V, vector<vector<int>>& prerequisites){
        
        //course -> prerequisite
        
        vector<int> indegree(V, 0);
        vector<vector<int>>adj(V);
	
        for(int i=0; i<prerequisites.size(); i++){

            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);

        }
        
		for (int i = 0; i < V; i++) {
			for (auto it : adj[i]) {
				indegree[it]++;
			}
		}

		queue<int> q;
		for (int i = 0; i < V; i++) {
			if (indegree[i] == 0) {
				q.push(i);
			}
		}

		int cnt = 0;
		// o(v + e)
		while (!q.empty()) {
			int node = q.front();
			q.pop();
			cnt++;
			// node is in your topo sort
			// so please remove it from the indegree

			for (auto it : adj[node]) {
				indegree[it]--;
				if (indegree[it] == 0) q.push(it);
			}
		}

		if (cnt == V) return true;
		return false;
	
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