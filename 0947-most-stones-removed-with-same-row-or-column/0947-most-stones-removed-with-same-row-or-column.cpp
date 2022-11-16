class DisjointSet {
    int _size;
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
        
        _size =n;
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
    
    int componentSize(){
        int ctr=0;
        for(int i=0; i<=_size; i++){
            if(parent[i]==i && size[i]>1)
                ctr++;
        }
        
        return ctr;
    }
};


class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        
        int N = stones.size();
        int maxRow=-1, maxCol =-1;
        for(auto row: stones){
            maxRow = max(row[0], maxRow);
            maxCol = max(row[1], maxCol);
        }
        
        DisjointSet ds(maxCol+maxRow+1);
        
        for(auto row: stones){
            
            ds.unionBySize(row[0], maxRow+1+row[1]);
        }
        
        //cout<<ds.componentSize()<<endl;
        return N-ds.componentSize();
    }
};