class Solution {
public:
    
    void BFS(int src, int dst, vector<int> &visited, vector<vector<pair<int, int>>> &adj, int k){
     
        
        queue<vector<int>> q;   //row,price, k
        vector<int> vec{src, 0, k+1};
        
        q.push(vec);
        visited[src] = 0;
        
        //cout<<"Loop"<<endl;
        while(!q.empty()){
            
            vec = q.front(); q.pop();
            
            if(vec[2]==0 || dst==vec[0]) continue;
            
            /*//visited[vec[0]] = vec[1];
            
            if(vec[0]==dst){
                //visited[vec[0]] = vec[1];
                continue;
            }*/
            
            
            
            //cout<<vec[2]<<" "<<vec[0]<<" "<<vec[1]<<endl;
            
            
            for(auto row: adj[vec[0]]){
            
                if(vec[1]+row.second <= visited[row.first]){
                    
                    visited[row.first] = vec[1]+row.second;
                    
                    vector<int> node{row.first, vec[1]+row.second, vec[2]-1 };
                    q.push(node);
                }
            
            
            
            }
            
        }
        
        
    }
    
    void DFS(int src, int dst, int curr_price, vector<bool> &visited, vector<vector<pair<int, int>>> &adj, int k, int &max_price){
        
        
        //cout<<"K: "<<k<<" "<<src<<endl;
        
        //k stops have been exhausted, it has to be the destination or stop
        if(k==0 && src!=dst)
            return;
        
        // If you meet the destination while K>0
        if(src==dst){
            max_price = min(max_price, curr_price);
            return;
        }
        
        visited[src] = true;
        
        for(auto row: adj[src]){
            
            if(visited[row.first]==false && curr_price+row.second <= max_price){
                
                DFS(row.first, dst, curr_price+row.second, visited, adj, k-1, max_price);
            }
            
            
            
        }
        
        visited[src] = false;
        
    }
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        //ios_base::sync_with_stdio(false);
        //cin.tie(NULL);
        //cout.tie(NULL);
        
        
        vector<vector<pair<int, int>>> adj(n);
        
        for(auto ele: flights){
            
            adj[ele[0]].push_back({ele[1], ele[2]});
            
        }
        
        vector<int> visited(n, 1e7);
        
        
                BFS(src, dst, visited, adj, k);
                
        
        /*for(int ele: visited){
            cout<<ele<<" ";
        }cout<<endl;
        */
        return visited[dst]==1e7 ? -1: visited[dst];
    }
};