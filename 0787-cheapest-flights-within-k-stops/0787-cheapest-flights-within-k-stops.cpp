class Solution {
public:
    
    struct Node{
        
        int node;
        int price;
        int k;
    };
    
    void BFS(int src, int dst, vector<int> &price, vector<vector<pair<int, int>>> &adj, int k){
     
        
        queue<Node> q;   //node,price, k
        //vector<int> vec{src, 0, k+1};
        
        q.push(Node{src, 0, k+1});
        price[src] = 0;
        
        //cout<<"Loop"<<endl;
        while(!q.empty()){
            
            Node state = q.front(); q.pop();
            
            //at k+1 the node is dst
            if(state.k==0 || dst==state.node)
                continue;
            
            if(state.k==0)
                continue;
            /*//visited[vec[0]] = vec[1];
            
            if(vec[0]==dst){
                //visited[vec[0]] = vec[1];
                continue;
            }*/
            
            
            
            //cout<<vec[2]<<" "<<vec[0]<<" "<<vec[1]<<endl;
            
            
            for(auto row: adj[state.node]){
            
                if(state.price+row.second <= price[row.first]){
                    
                    price[row.first] = state.price+row.second;
                    
                    q.push( Node{row.first, price[row.first], state.k-1 } );
                }
            
            
            
            }
            
        }
        
        
    }
    
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        
        
        vector<vector<pair<int, int>>> adj(n);
        
        for(auto ele: flights)            
            adj[ele[0]].push_back({ele[1], ele[2]});
            
        //Default maxx Price
        vector<int> price(n, 1e7);
        
        
        BFS(src, dst, price, adj, k);
                
        
        /*for(int ele: price){
            cout<<ele<<" ";
        }cout<<endl;
        */
        return price[dst]==1e7 ? -1: price[dst];
    }
};