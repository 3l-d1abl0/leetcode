class Solution {
public:
    
    void findSubtreeSizeandDistance(int node, int parent, vector<vector<int>> &adj, vector<int> &subSize, vector<int> &pathSum){

    //base
    subSize[node] = 1;
    pathSum[node] = 0;
    
    for(int child: adj[node]){

        if(child!=parent){

            findSubtreeSizeandDistance(child, node, adj, subSize, pathSum);

            subSize[node] +=subSize[child];

            pathSum[node]+= pathSum[child]+ (subSize[child]*1); //(no of nodes in subtree with root[child] * weight of the new Edge from node-child)

        }

    }


}

void reroot(int node, int parent, int N, vector<vector<int>> &adj, vector<int> &subSize, vector<int> &pathSum){


    if(parent!=-1){

        //cout<<node<<" :: "<<( pathSum[parent]-(pathSum[node]+ (1*subSize[node])) ) + N-subSize[node]<<endl;
        pathSum[node] += ( pathSum[parent]-(pathSum[node]+ (1*subSize[node])) ) + N-subSize[node];
    }

    for(int child: adj[node]){

        if(child!=parent){

            reroot(child, node, N, adj, subSize, pathSum);
        }
    }

}
    
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
 
        
        vector<int> subSize(N, 0);
        vector<int> pathSum(N, 0);
        
        if(N==1)
            return pathSum;
        
        
        vector<vector<int>> adj(N, vector<int>());
        for(auto row: edges){
            adj[row[0]].push_back(row[1]);
            adj[row[1]].push_back(row[0]);
        }
        
        findSubtreeSizeandDistance(0, -1, adj, subSize, pathSum);
        
        reroot(0, -1, N, adj, subSize, pathSum);
        
        
        return pathSum;
        
    }
};