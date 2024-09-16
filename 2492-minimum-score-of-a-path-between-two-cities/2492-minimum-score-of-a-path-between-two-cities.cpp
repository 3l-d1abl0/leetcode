class DSU{
  
    vector<int> parent;
    vector<int> size;
    int sz;
    
    public:
    
    DSU(int n){
        
        sz = n;
        size.resize(n+1, 1);
        parent.resize(n+1, 0);
        for(int i=1; i<=n; i++){
            parent[i] = i;
        }
    }
    
    int findParent(int node){
        
        if(parent[node]==node)
            return node;
        
        return parent[node] = findParent(parent[node]);
    }
    
    void unionBySize(int u, int v){
        
        int pu = findParent(u);
        int pv = findParent(v);
        
        if(pu != pv){
            
            if(size[pv] >= size[pu]){
                parent[pu] = pv;
                size[pv]++;
            }else{
                
                parent[pv] = pu;
                size[pu]++;
            }
        }
    }
};



class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        
        vector<int> dist(n+1, 1e9);
        DSU ds(n);
        
        for(auto road: roads){
            
            ds.unionBySize(road[0], road[1]);
            
            dist[road[0]] = min(dist[road[0]], road[2]);
            dist[road[1]] = min(dist[road[1]], road[2]);
         }
        
        int parent1 = ds.findParent(1);
        int minn = 1e9;
        for(int i=1; i<=n; i++){
            if(ds.findParent(i) == parent1)
                minn = min(minn, dist[i]);
        }
        
        
        return minn;
    }
};