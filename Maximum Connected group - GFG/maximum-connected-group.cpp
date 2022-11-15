//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class DSU{
    
    private:
        int noc;
        vector<int> parent;
        vector<int> size;
    
    public:
    
        DSU(int N){
                
            noc = N;
            for(int i=0; i<N; i++){
                parent.push_back(i);
                size.push_back(1);
            }
        }
    
    
        int findParent(int node){
                
            if(parent[node]==node)  return node;
            else
                return parent[node] = findParent(parent[node]);
        }
    
        int getSize(int node){
            
            //int pu = findParent(node);
            
            return size[node];
        } 
    
        void unionn(int u, int v){
            
            int pu = findParent(u);
            int pv = findParent(v);
            
            
            if(pu != pv){
                
                
                if(size[pu]>size[pv]){
                    parent[pv]=pu;
                    size[pu]+=size[pv];
                }else{
                    parent[pu] =pv;
                    size[pv] += size[pu];
                }
            }
            
        }//union
        
};


class Solution {
  public:
    int MaxConnection(vector<vector<int>>& grid) {
        // code here
        
        int N = grid.size();
        
        DSU ds(N*N);
        
        int dx[] ={-1, 0, 1, 0};
        int dy[] ={0, 1, 0, -1};
        
        int max_sz = -1;
        //make the components
        for(int x=0; x<N; x++){
            
            for(int y=0; y<N; y++){
                
                if(grid[x][y]==0)   continue;
                
                int d1Node = N*x+y;
                //cout<<"1d :: "<<d1Node<<endl;
                for(int i=0; i<4; i++){
                    
                    int newX = x+dx[i];
                    int newY = y+dy[i];
                    if(newX>=0 && newX<N && newY>=0 && newY <N && grid[newX][newY]==1){
                            
                            
                            int d1Adj = N*newX+newY;
                            ds.unionn(d1Node, d1Adj);
                            //cout<<d1Node<<" -> "<<d1Adj<<endl;
                    }
                }//for
                
                //get the max size of comp
                max_sz = max(max_sz, ds.getSize(ds.findParent(d1Node)) );
                //cout<<max_sz<<" -- "<<endl;
                
            }
        }//for x
        
        
        //check each 0 if turned 1
        for(int x=0; x<N; x++){
            
            for(int y=0; y<N; y++){
                
                if(grid[x][y]==1)   continue;
                
                int d1Node = N*x+y;
                //cout<<"1d :: "<<d1Node<<endl;
                
                //vector<bool> parent(N*N, false);
                unordered_set<int> parents;
                int sz =1;
                
                for(int i=0; i<4; i++){
                    
                    int newX = x+dx[i];
                    int newY = y+dy[i];
                    if(newX>=0 && newX<N && newY>=0 && newY <N && grid[newX][newY]==1){
                            
                            
                            int d1Adj = N*newX+newY;
                            int p = ds.findParent(d1Adj);
                            if(parents.find(p)==parents.end()){
                                sz += ds.getSize(p);
                                parents.insert(p);
                            }
                            
                    }
                }//for i
                
                
                
                
                //get the max size of comp
                max_sz = max(max_sz, sz);
                //cout<<max_sz<<" -- "<<endl;
                
            }
        }//for x
        
        
        return max_sz;
        
        
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        Solution obj;
        cout<<obj.MaxConnection(grid)<<"\n";
    }
}

// } Driver Code Ends