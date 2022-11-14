class Solution {
public:
    
    class UnionFind{
        
        private:
            vector<int> parent;
            vector<int> rank;
            int _size;
        
        public:
            UnionFind(int N){
                
                _size = N;
                parent.resize(N);
                rank.resize(N);
                
                for(int i=0; i<_size; i++){
                    parent[i] = i;
                    rank[i] =1;
                }
            }
        
        
            int findParent(int v){
                if(parent[v] ==v) return v;
                else return parent[v] = findParent(parent[v]);
            }
        
            void merge(int u, int v){
                
                int pu = findParent(u);
                int pv = findParent(v);
                
                if(pu!=pv){
                    
                    if(rank[pu] == rank[pv]){
                        
                        parent[pu]=pv;
                        rank[pv]++;
                    }else if(rank[pu]>rank[pv]){
                        parent[pv] = pu;
                    }else{
                        parent[pu] = pv;
                    }
                    
                }
            }
    };
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        
        int N = isConnected.size();
        
        UnionFind uf(N);
        
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                
                if(isConnected[i][j]==1)
                    uf.merge(i, j);
            }
        }
        
        int ctr=0;
        for(int i=0; i<N; i++){
            
            if(uf.findParent(i)==i)
                ctr++;
        }
        
        return ctr;
    }
};