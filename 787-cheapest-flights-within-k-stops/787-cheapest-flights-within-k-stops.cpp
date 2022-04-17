class Solution {
public:
    
    int dijkstra(int src, int dst, int k, vector<vector<pair<int, int>>> &adj, int n){
        
        
        priority_queue< vector<int>, vector<vector<int>>, greater<vector<int>> >  pq;
        //smallest distance first
        
        
        vector<int> dist(n+1, 1e7); dist[src]=0;
        vector<int> hops(n+1, 1e7); hops[src]=0;
        
        
        pq.push({ 0, 0, src});    //cost, hops, vertex
        
        
        while(!pq.empty()){
            
            auto ele = pq.top(); pq.pop();
            int currDist = ele[0], currHops = ele[1], node = ele[2];
           
           // cout<<"c:"<<currDist<<" h:"<<currHops<<" v:"<<node<<endl;
            if(node==dst) return currDist;
            
            if(currHops==k+1) continue;
            
            for(auto row: adj[node]){
                
                if(currDist + row.second < dist[row.first] || currHops+1 <hops[row.first]){
                    //cout<<node<<"->"<<row.first<<endl;    
                    dist[row.first] = currDist +row.second;
                    hops[row.first] = currHops+1;
                    
                    pq.push({dist[row.first], hops[row.first], row.first});
                }
                
            }
            
            
        }
        
        
        /*for(int i=0; i<n; i++){
            cout<<dist[i]<<","<<hops[i]<<" ";
        }*/
        
        return -1;
        
    }
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        
        
        vector<vector<pair<int, int>>> adj (n);
        for(auto row: flights){
            adj[row[0]].push_back({row[1], row[2]}); //v, wt
        }
        
        
        return dijkstra(src, dst, k, adj, n);
    }
};