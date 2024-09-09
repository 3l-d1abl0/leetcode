class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        
        vector<vector<pair<int, bool>>> adj(n);
        //RED- true, BLUE - false
        
        for(auto row: redEdges)
            adj[row[0]].push_back({row[1], true});
        
        for(auto row: blueEdges)
            adj[row[0]].push_back({row[1], false});
        
        
        queue<tuple<int, bool>> q;
        //node, dist, lastEdge
        q.push({0, true});   //last Edge red
        q.push({0, false});  //last edge blue
        
        vector<vector<int>> dist(n, vector<int>(2, INT_MAX));
        dist[0][1] = 0;  //RED
        dist[0][0] = 0;  //FALSE
        
        while(!q.empty()){
            
            auto [node, lastEdge] = q.front();
            q.pop();
            
            for(auto row: adj[node]){
                
                int neigh = row.first;
                bool currEdge = row.second;
                
                //cout<<neigh<<" "<<currEdge<<endl;
                
                if(lastEdge != currEdge){   //alternate
                    
                    if( dist[neigh][currEdge] > dist[node][lastEdge]+1 ){
                        dist[neigh][currEdge] = dist[node][lastEdge]+1;
                        q.push({neigh, currEdge});
                    }
                }
                
            }//for
            
        }//whiile
        
        
        vector<int> dis(n);
        for(int i=0; i<n; i++){
            dis[i] = min(dist[i][0], dist[i][1]);
            
            if(dis[i]==INT_MAX)
                dis[i] = -1;
        }

        
        return dis;
    }
};