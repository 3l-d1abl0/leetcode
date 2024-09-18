class DSU{
    
    int N;
    vector<int> size;
    vector<int> parent;
    int join;
    public:
    
    DSU(int n){
        join =0;
        N = n;
        size.resize(n, 0);
        parent.resize(n, 0);
        
        for(int i=0; i<n; i++)
            parent[i] =i;
    }
    
    int findParent(int u){
        
        if(parent[u]==u)
            return u;
        
        return parent[u] = findParent(parent[u]);
    }
    
    void unionBySize(int u, int v){
        
        cout<<"Joining : "<<u<<" "<<v<<endl;
        
        int pv = findParent(v);
        int pu = findParent(u);
        
        if(size[pu] == 0)
            size[pu] =1;
        if(size[pv] == 0)
            size[pv] =1;
        
        if(pv!=pu){
            
            if(size[pv] >= size[pu]){
                parent[pu] = pv;
                size[pv] += size[pu];
            }else{
                parent[pv] = pu;
                size[pu] += size[pv];
            }
        }else{
            join++;
            cout<<u<<", "<<v<<endl;
        }
        
        //cout<<"Size : "<<size[pu]<<" "<<size[pv]<<endl;
    }//unionBySize
    
    int findServers(){
        
        /*
        for(int i=0; i<N; i++){
            cout<<parent[i]<<" ";
        }
        cout<<endl;
        */
        for(int i=0; i<N; i++){
            cout<<size[i]<<" ";
        }
        cout<<endl;
        
        cout<<"join:: "<<join<<endl;
        
        int serverCount =0;
        for(int i=0; i<N; i++){
            if(i==parent[i] && size[i]>2){
                cout<<size[i]-1<<"* ";
                serverCount += (size[i]-1);
                
            }
        }
        
        return serverCount+join;
    }
    
};

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        
        int R = grid.size();
        int C = grid[0].size();
        
        DSU ds(R+C);
        
        for(int i=0; i<R; i++){
            for(int j=0; j<C; j++){
                
                if(grid[i][j] ==1){
                    ds.unionBySize(i, R+j);
                }
            }
        }//for i
        
        return ds.findServers();
        
    }
};