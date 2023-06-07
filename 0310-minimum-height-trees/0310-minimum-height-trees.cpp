class Solution {
public:
    
    
    vector<int> minHeightTree(int V, vector<vector<int>> &edges){

        int TotalNodes = V;
        vector<int> indegree(V, 0);
        vector<vector<int>> adj(V, vector<int>());

        for(auto edge: edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);

            indegree[edge[0]]++;
            indegree[edge[1]]++;
        }

        vector<int> ans;
        queue<int> q;
        for(int i=0; i<V; i++){
            if(indegree[i]==1) q.push(i);

            if(indegree[i]==0) ans.push_back(i);

        }

        //For the tree-alike graph, the number of centroids is no more than 2.
        while(TotalNodes>2){

                int qSz = q.size();
                TotalNodes -= qSz;

                for(int i=0; i<qSz; i++){

                    int node = q.front(); q.pop();

                    for(int neigh: adj[node]){

                            indegree[neigh]--;
                            if(indegree[neigh]==1)
                                q.push(neigh);
                    }
                }
        }

        while(!q.empty()){
            ans.push_back(q.front());
            q.pop();
        }

        return ans;
    }
    
    
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
  
            return minHeightTree(n, edges);
    }
};