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
    
        vector<int> method1(int n, vector<vector<int>> &edges){
        return minHeightTree(n, edges);
    }
    
    
        void dfsFindHeight(int node, int parent, vector<vector<int>> &adj, vector<int> &height){

        height[node] = 0;

        for(int child: adj[node]){

            if(child!=parent){

                dfsFindHeight(child, node, adj, height);

                height[node] = max(height[node], 1+height[child]);
            }
        }

    }
    
    
        void dfsReRoot(int node, int parent, vector<vector<int>> &adj, vector<int> &height, vector<int> &maxHeight){

        //1. For the particular node, find 2 max heights from child
        int max1 = -1, max2=-1;
        for(int child: adj[node]){

            if(child!=parent){
                cout<<height[child]<<" ";
                if(height[child]> max1){
                    max2 = max1;
                    max1 = height[child];
                }else if(height[child] > max2){
                    max2 = height[child];
                }
            }
        }

        
        //2. Travers each child
        for(int child: adj[node]){

            if(child!=parent){

                //1. If the child itself lies in the max height path from the parent, try the second max height
                if(height[child]==max1){
                        maxHeight[child] = max(maxHeight[node]+1, max2+2);
                }else{
                    maxHeight[child] = max(maxHeight[node]+1, max1+2);
                }

                dfsReRoot(child, node, adj, height, maxHeight);

            }
        }



    }

    vector<int> method2(int N, vector<vector<int>> &edges){

        vector<vector<int>> adj(N, vector<int>());

        for(auto row: edges){
            adj[row[1]].push_back(row[0]);
            adj[row[0]].push_back(row[1]);
        }

        vector<int> height(N, 0);
        vector<int> maxHeight(N, 0);


        dfsFindHeight(0, -1, adj, height);

        dfsReRoot(0, -1, adj, height, maxHeight);

        int minn = 1e7;
        int maxLen = -1;
        vector<int> ans;
        for(int i=0; i<N; i++){

            maxLen = max(height[i], maxHeight[i]);
            if(maxLen<minn){
                ans = {i};
                minn = maxLen;
            }else if(maxLen==minn){
                ans.push_back(i);
            }
        }

        return ans;
    }
    
    
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
  
                        //1. topo Sort
            //return method1(n, edges);

            //2. Re rooting
            return method2(n, edges);
    }
    
};