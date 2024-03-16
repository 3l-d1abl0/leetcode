class Solution {
public:
    
    struct Node{
        
        int node;
        int price;
        int k;
    };
    
    void BFS(int src, int dst, vector<int> &price, vector<vector<pair<int, int>>> &adj, int k){
     
        
        queue<Node> q;   //node,price, k
        
        q.push(Node{src, 0, k+1});
        price[src] = 0;
        
        //cout<<"Loop"<<endl;
        while(!q.empty()){
            
            Node state = q.front(); q.pop();
            
            //at k+1 the node is dst
            if(state.k==0 || dst==state.node)
                continue;
            
            //If k stops have passed and not reached the destination, no point in going further
            if(state.k==0)
                continue;
            
            for(auto row: adj[state.node]){
            
                if(state.price+row.second <= price[row.first]){
                    
                    price[row.first] = state.price+row.second;
                    
                    q.push( Node{row.first, price[row.first], state.k-1 } );
                }

            }//for
            
        }//while
        
        
    }
    
    //return method1(n, adj, src, dst, k);
    int method1(int n, vector<vector<pair<int, int>>> &adj, int src, int dst, int k) {
        
        //Default maxx Price
        vector<int> price(n, 1e7);
        
        BFS(src, dst, price, adj, k);
        
        return price[dst]==1e7 ? -1: price[dst];
        
    }
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        
        
        vector<vector<pair<int, int>>> adj(n);
        
        for(auto ele: flights)            
            adj[ele[0]].push_back({ele[1], ele[2]});
    
        
        return method1(n, adj, src, dst, k);    //16ms BFS
        
    }
};