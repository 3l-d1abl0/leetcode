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
    
    
    void dfs(int idx, vector<bool> &visited, vector<vector<int>> &isConnected){
        
        visited[idx] = true;
        
        for(int j=0; j<isConnected[idx].size(); j++){
            if(isConnected[idx][j] ==1 && !visited[j]){
                dfs(j, visited, isConnected);
            }
        }
    }
    
    int method1(vector<vector<int>> &isConnected, int N){
        
        
        vector<bool> visited(N, false);
        int ctr=0;
        for(int i=0; i<N; i++){
            if(visited[i]==false){
                dfs(i, visited, isConnected);
                ctr++;
            }
        }
        
        return ctr;
    }
    
    
    int method2(vector<vector<int>>& isConnected, int N){
        
        UnionFind uf(N);
        //Traverse the matrix and 
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                //merge if these 2 are connected
                if(isConnected[i][j]==1)
                    uf.merge(i, j);
            }
        }
        
        int ctr=0;
        for(int i=0; i<N; i++){
            //count the Leaders
            if(uf.findParent(i)==i)
                ctr++;
        }
        
        return ctr;
        
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        
        int N = isConnected.size();
        
        //Mrthod1 - DFS - TC: O(V*V) Since its an adj Matrix
        //return method1(isConnected, N);
        
        //Method2 - UnionFind
        return method2(isConnected, N);
        

    }
};