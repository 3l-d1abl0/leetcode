class Solution {
public:
    
    int dijkstra(int src, vector<vector<pair<int,int>>> &adj, int n){
        
        
        vector<int> dist (n+1, 1e7); dist[src] =0;
        
        priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
        
        pq.push({0, src});
        
        while(!pq.empty()){
            
            auto ele = pq.top(); pq.pop();
            int time = ele.first, node= ele.second;
            //cout<<"Processing : "<<node<<" with time "<<time<<endl;
            
            for(auto adjNode: adj[node]){
                
                int vtx = adjNode.first, t = adjNode.second;
                
                if(dist[node]+t < dist[vtx]){
                    
                    dist[vtx] = dist[node]+t;
                    pq.push({ dist[vtx], vtx});
                    
                   // cout<<"To heap : "<<vtx<<" with time "<<dist[vtx]<<endl;
                    
                }
            }
            
        }
        
        
        /*for(int ele: dist){
            cout<<ele<<" ";
        }*/
        
        int maxx = *max_element(dist.begin()+1, dist.end()); 
        if (maxx == 1e7){
            return -1;
        }else{
            return maxx;
        }
        
    }
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        
        vector<vector<pair<int,int>>> adj(n+1);
        
        for(auto ele: times){
            adj[ele[0]].push_back({ele[1], ele[2]});
        }
            
        
        
        return dijkstra(k, adj, n);
        
        
        
        
        
        
    }
};