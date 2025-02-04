class DSU{
    
    int N;
    vector<int> size;
    vector<int> parent;
    int join;
    public:
    
    DSU(int n){
        join =0;
        N = n;
        size.resize(n, 1);
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
        
        //cout<<"Joining : "<<u<<" "<<v<<endl;
        
        int pv = findParent(v);
        int pu = findParent(u);
        
        // if(size[pu] == 0)
        //     size[pu] =1;
        // if(size[pv] == 0)
        //     size[pv] =1;
        
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
            //cout<<u<<", "<<v<<endl;
        }
        
        //cout<<"Size : "<<size[pu]<<" "<<size[pv]<<endl;
    }//unionBySize
    
    int findServersWithSize2(){
        
        /*
        for(int i=0; i<N; i++){
            cout<<size[i]<<" ";
        }
        cout<<endl;
        
        cout<<"join:: "<<join<<endl;
        */
        
        int serverCountSize2 =0;
        for(int i=0; i<N; i++){
            if(i==parent[i] && size[i]==2){
                
                serverCountSize2++;
                
            }

            //cout<<size[i]<<" ";
        }

        //cout<<endl;
        
        return serverCountSize2;
    }
    
};

class Solution {
public:
    
    int method1(vector<vector<int>>& grid){
                int R = grid.size();
        int C = grid[0].size();
        
        vector<int> hor(R, 0);
        vector<int> ver(C, 0);
        
        for(int i=0; i<R; i++){
            for(int j=0; j<C; j++){
                
                if(grid[i][j]==1){
                    hor[i]++;
                    ver[j]++;
                }
            }//for j
        }//for i
        
        
        int count=0;
        for(int i=0; i<R; i++){
            for(int j=0; j<C; j++){
                if(grid[i][j] ==1 && (hor[i]>1 || ver[j]>1) )
                    count++;
            }//for j
        }//for i
        
        
        return count;
    }
    
    int method2(vector<vector<int>>& grid){
        
        
        int R = grid.size();
        int C = grid[0].size();
        
        DSU ds(R+C);
        
        int serverCount=0;
        for(int i=0; i<R; i++){
            for(int j=0; j<C; j++){
                
                if(grid[i][j] ==1){
                    serverCount++;
                    ds.unionBySize(i, R+j);
                }
            }
        }//for i
        //server with size 2 means its not connected to any other server
        return serverCount - ds.findServersWithSize2();
    }
    
    int countServers(vector<vector<int>>& grid) {
        
        /*
            method1: frequency
            TC: O(M*N)
            SC: O(M+N)
        */
        //return method1(grid);
        
        /*
            method2 : DSU
            count the total servers, remove the ones which are not connected
            TC: N.O(alpha), inverse ackerman Function
            SC: O(N)
            
        */
        
        return method2(grid);

        //method3 : DFS
        
    }
};