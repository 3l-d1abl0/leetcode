//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++


class DisjointSet{
    
    private:
    
        vector<int> parent;
        vector<int> size;
        vector<int> rank;
        int _size;
    public:
    
        DisjointSet(int N){
            
            parent.resize(N+1);
            size.resize(N+1, 1);
            rank.resize(N+1, 0);
            
            _size = N+1;
            
            
            for(int i=0; i<=N; i++){
                parent[i]=i;
            }
        }
        
        
        int findParent(int node){
            
            if(node == parent[node])
                return node;
            else
                parent[node] = findParent(parent[node]);
        }
        
        
        void unionBySize(int u, int v){
            
            int pu = findParent(u);
            int pv = findParent(v);
            
            if(pu!=pv){
                
                if(size[pv]>=size[pu]){
                    parent[pu] = pv;
                    size[pv]+= size[pu];
                }else{
                    parent[pv] = pu;
                    size[pu]+=size[pv];
                }
                
            }
            
        }
        
        void unionByRank(int u, int v){
            
            
            int pu = findParent(u);
            int pv = findParent(v);
            
            
            if(pu!=pv){
                
                if(rank[pu]==rank[pv]){
                    parent[pv] = pu;
                    rank[pu]++;
                }else if(rank[pu] < rank[pv]){
                    parent[pu] = pv;
                }else{
                    parent[pv] =pu;
                }
            }
        }
    
};



class Solution {
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        
        vector<vector<bool>> matrix (n, vector<bool> (m, false));
        
        int comp =0;
        DisjointSet ds(n*m);
        vector<int> ans;
        for(auto row: operators){
            
            int x = row[0];
            int y = row[1];
            int node_id = (x*m) +y;
            
            if(matrix[x][y]==true){
                ans.push_back(comp);
                continue;
            }
            
            comp++;
            matrix[x][y] =true;
            
            
            vector<int> xx{-1, 0, 1, 0};
            vector<int> yy{0, 1, 0, -1};
            
            for(int i=0; i<4; i++){
                
                int dx = x+xx[i], dy = y+yy[i];
                
                if(0<=dx  && dx <=n-1 && 0<=dy && dy<=m-1){
                    
                    if(matrix[dx][dy]==true){
                        
                        int node_id_neigh = (dx*m) +dy;
                        if(ds.findParent(node_id) != ds.findParent(node_id_neigh)){
                            
                            comp--;
                            ds.unionByRank(node_id, node_id_neigh);
                        }
                    }
                    
                }
                
            }//for
            
            
            ans.push_back(comp);
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends