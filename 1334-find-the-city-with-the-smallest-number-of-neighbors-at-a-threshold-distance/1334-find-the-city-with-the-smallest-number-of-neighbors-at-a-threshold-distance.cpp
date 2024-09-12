class Solution {
public:
    
    int floydWarshall(int n, vector<vector<int>>& edges, int distanceThreshold){
        
        //Create a Adj Matrix
        vector<vector<int>> dist(n, vector<int> (n, INT_MAX));
		for (auto it : edges) {
			dist[it[0]][it[1]] = it[2];
			dist[it[1]][it[0]] = it[2];
		}
		
        //same node-node has 0 weight
        for (int i = 0; i < n; i++)
            dist[i][i] = 0;
        
        
		for (int via = 0; via < n; via++) {
		
            for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
                    
                    //If unreachabel , skip
					if (dist[i][via] == INT_MAX || dist[via][j] == INT_MAX)
						continue;
                    
					dist[i][j] = min(dist[i][j], dist[i][via] + dist[via][j]);
				}
			}
		}
        
        
        
		int cntCity = n;
		int cityNo = -1;
        
        //For every city m check how many it can reach and how many are within threshold
		for (int city = 0; city < n; city++) {
			int cnt = 0;
			for (int adjCity = 0; adjCity < n; adjCity++) {
                
                
				if (city != adjCity && dist[city][adjCity] <= distanceThreshold)
					cnt++;
			}

			if (cnt <= cntCity) {
				cntCity = cnt;
				cityNo = city;
			}
		}
        
		return cityNo;
        
        
    }
    
    void dijks(int source, vector<int> &dist, vector<vector<pair<int,int>>> &adj){
        
        //Min Heap - weight, node
        priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> >pq;
        
        dist[source] = 0;
        
        pq.push({0, source});
        
        
        while(!pq.empty()){
            
            pair<int, int> node = pq.top();
            pq.pop();
            
            for(pair<int, int> ele: adj[node.second]){
                
                if(dist[ele.first] > dist[node.second]+ele.second){
                    dist[ele.first] = dist[node.second]+ele.second;
                    
                    pq.push({dist[ele.first], ele.first});
                }
                
            }
            
        }
        
        
        
    }
    
    int Dijkstra(int n, vector<vector<int>>& edges, int distanceThreshold){
        
        vector<vector<pair<int,int>>> adj(n);//vector<pair<int, int>>);
        
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0], v = edges[i][1], w = edges[i][2];   
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        
        int MAXCITY = n;
        int city = -1;
        
        //For every node as source, apply Dijkstra
        for(int i=0; i<n; i++){
            
            vector<int> dist(n, INT_MAX);
            dijks(i, dist, adj);
            
            
            /*
            Check how many are reachable from the given source,
            and how many have the Threashold
            */
            int ctr =0;
            for(int j=0; j<n; j++){
                //cout<<dist[j]<<" ";
                if(i==j || dist[j]==INT_MAX) continue;
                if(dist[j]<=distanceThreshold)
                    ctr++;
            }
            //cout<<endl;
            if(ctr<=MAXCITY){
                MAXCITY = ctr;
                city = i;
            }
        }//for
        
        return city;
           
    }
    
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        //19ms
        return floydWarshall(n, edges, distanceThreshold);  //O(n^3)
        
        //Apply dij for each node - 
        //return Dijkstra(n, edges, distanceThreshold);   //O(V+ElogV)
        
    }
};