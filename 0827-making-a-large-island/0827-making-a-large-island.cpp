static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class DisjointSet {
	int _size;
    vector<int> parent, size;
public:
    DisjointSet(int n) {
        //rank.resize(n+1, 0);
        parent.resize(n+1);
        size.resize(n+1);
        for(int i = 0;i<=n;i++) {
            parent[i] = i;
            size[i] = 1;
        }

        _size = n;
    }

    int findParent(int node) {
        if(node == parent[node])
            return node;
        return parent[node] = findParent(parent[node]);
    }

    /*void unionByRank(int u, int v) {
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
    }*/

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
    
    int getSize(int p){
        
        p = findParent(p);
        return size[p];
    }
};


class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        
        int N = grid.size();
        
        DisjointSet ds(N*N);
        
        int dx[] ={-1, 0, 1, 0};
        int dy[] ={0, 1, 0, -1};
        
        int max_sz = -1;
        
        //make the components
        for(int x=0; x<N; x++){
            
            for(int y=0; y<N; y++){
                
                if(grid[x][y]==0)   continue;
                
                int node_idx = (N*x)+y;
                
                for(int i=0; i<4; i++){
                    
                    int newX = x+dx[i], newY = y+dy[i];
                    if(newX>=0 && newX<N && newY>=0 && newY <N && grid[newX][newY]==1){
                            
                            
                            int neighour_node_id = N*newX+newY;
                            ds.unionBySize(node_idx, neighour_node_id);
                            
                    }
                }//for i
                
                //get the max size of comp
                max_sz = max(max_sz, ds.getSize(node_idx));
                
            }//for y
        }//for x
        
        
        //check each 0 if turned 1
        for(int x=0; x<N; x++){
            
            for(int y=0; y<N; y++){
                
                if(grid[x][y]==1)   continue;
                
                //int node_idx = (N*x)+y;
                //cout<<"1d :: "<<d1Node<<endl;
                
                //vector<bool> parent(N*N, false);
                unordered_set<int> parents;
                
                for(int i=0; i<4; i++){
                    
                    int newX = x+dx[i];
                    int newY = y+dy[i];
                    if(newX>=0 && newX<N && newY>=0 && newY <N && grid[newX][newY]==1){
                            
                            
                            int neighour_node_id = N*newX+newY;
                            int p = ds.findParent(neighour_node_id);
                            parents.insert(p);
                            
                    }
                }//for i
                
                int sz =1;
                
                for(int ele : parents){
                    sz += ds.getSize(ele);
                }
                
                //get the max size of comp
                max_sz = max(max_sz, sz);
                
            }
        }//for x
        
        
        return max_sz;
        
        
    }
};