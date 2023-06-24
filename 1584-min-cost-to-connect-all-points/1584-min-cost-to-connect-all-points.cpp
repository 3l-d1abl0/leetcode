class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        
        int N = points.size();
        vector<vector<tuple<int, long long>>> adj(N);
        
        
        //1, make the adj List
        for(int i=0; i<N; i++){
                
            
            int x1= points[i][0];
            int y1 = points[i][1];
            
            for(int j=i+1; j<N; j++){


                int x2= points[j][0];
                int y2 = points[j][1];

                long long dist = abs(x1-x2) + abs(y1-y2);

                adj[i].push_back({j, dist});
                adj[j].push_back({i, dist});
                
            }
            
        }
        
        
        
        /*for(int i=0; i<N; i++){
            
            for(int j=0; j<adj[i].size(); j++){
                
                auto [src, wt] = adj[i][j];
                cout<<i<<" --> "<<src<<" :: "<<wt<<endl;
            }
        }*/
        
        //2. Perform Prim's
        
        priority_queue<tuple<long long, int>, vector<tuple<long long, int>>, greater<tuple<long long, int>> > pq;//min Queue
        
        
        //vector<long long> nodeWt(N, 1e13);
        vector<bool> isMst(N, false);
        
        //nodeWt[0] =0;
        pq.push({0, 0});    //dist, src
        long long cost =0;
        
        
        while(!pq.empty()){
         //for(int i = 0; i<N; i++){  
            auto [dist, node] = pq.top(); pq.pop();
            
            if(isMst[node] == false){
                cost += dist;
                isMst[node] = true;
                
                //cout<<"node:: "<<node<<" dist:: "<<dist<<endl;

                for(auto [src, wt]: adj[node]){


                    if(isMst[src]== false /*&& nodeWt[src]> wt*/){
                        //nodeWt[src] = wt;
                        pq.push({wt, src});
                    }

                }
          }
            
            
        }//while
        
        
        return cost;
    }
};