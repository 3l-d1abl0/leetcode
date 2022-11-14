class DisjointSet {
    vector<int> rank, parent, size; 
public: 
    DisjointSet(int n) {
        rank.resize(n+1, 0); 
        parent.resize(n+1);
        size.resize(n+1); 
        for(int i = 0;i<=n;i++) {
            parent[i] = i; 
            size[i] = 1; 
        }
    }

    int findParent(int node) {
        if(node == parent[node])
            return node; 
        return parent[node] = findParent(parent[node]); 
    }

    void unionByRank(int u, int v) {
        int pu = findParent(u); 
        int pv = findParent(v); 
        
        if(pu != pv){
            
            if(rank[pu] < rank[pv]) {
                parent[pu] = pv; 
            }
            else if(rank[pv] < rank[pu]) {
                parent[pv] = pu; 
            }
            else {
                parent[pv] = pu; 
                rank[pu]++; 
            }
        }
    }

    void unionBySize(int u, int v) {
        int pu = findParent(u); 
        int pv = findParent(v); 
        
        if(pu != pv){
            
            if(size[pv] >= size[pu]) {
                parent[pu] = pv; 
                size[pv] += size[pu]; 
            }else{
                parent[pv] = pu;
                size[pu] += size[pv]; 
            }
            
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        DisjointSet ds(n);
        
        int ext =0;
        for(auto row: connections){
            
            if(ds.findParent(row[0]) == ds.findParent(row[1])){
                ext++;
            }else{
                ds.unionBySize(row[0], row[1]);
            }
            
        }
        
        int components =0;
        for(int i=0;i<n; i++){
            if(ds.findParent(i) == i)
                components++;
        }
        
        
        if(ext>= (components-1))
            return components-1;
        
        
        return -1;
        
    }
};