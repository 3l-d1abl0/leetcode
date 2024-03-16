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
    
    int method1(int n, vector<vector<pair<int, int>>> &adj, int src, int dst, int k) {
        
        //Default maxx Price
        vector<int> price(n, 1e7);
        
        BFS(src, dst, price, adj, k);
        
        return price[dst]==1e7 ? -1: price[dst];
        
    }
    
    
    
    int method2(int n, vector<vector<pair<int, int>>> &adj, int src, int dst, int k) {
        
        
        priority_queue< vector<int>, vector<vector<int>>, greater<vector<int>> >  minHeap;
        //smallest distance first
        
        
        vector<int> price(n+1, 1e7); 
        vector<int> hops(n+1, 1e7); //Ks
        
        price[src]=0;
        hops[src]=0;
        
        minHeap.push({ 0, 0, src});    //cost, hops, vertex
        
        
        while(!minHeap.empty()){
            
            
            auto ele = minHeap.top(); minHeap.pop();
            
            int currPrice = ele[0], currHop = ele[1], node = ele[2];
           
            /*
            At this point if the node is euql to distance 
            this is the minimum price it could get within k hops
            
            as we are restricting below th e hops in If condition
            */
            if(node==dst)
                return currPrice;
            
            //Maximum permitted Hop
            if(currHop==k+1)
                continue;
            
            for(auto row: adj[node]){
                
                
                //restrict the Hops too
                if(currPrice + row.second < price[row.first] || currHop+1 <hops[row.first]){
                    //cout<<node<<"->"<<row.first<<endl;    
                    price[row.first] = currPrice +row.second;
                    hops[row.first] = currHop+1;
                    
                    minHeap.push({price[row.first], hops[row.first], row.first});
                }
                
            }
            
            
        }//while
        
        return -1;

    }
    
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        
        
        vector<vector<pair<int, int>>> adj(n);
        
        for(auto ele: flights)            
            adj[ele[0]].push_back({ele[1], ele[2]});
    
        
        //return method1(n, adj, src, dst, k);    //16ms BFS
        return method2(n, adj, src, dst, k);    //20ms Dijkstra
        
    }
};