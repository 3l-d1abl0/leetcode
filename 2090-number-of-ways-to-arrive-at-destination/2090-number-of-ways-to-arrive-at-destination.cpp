class Solution {
public:
    int countPaths(int N, vector<vector<int>>& roads) {
        
        //Descreasing by Default
        //Ascending
        priority_queue<tuple<long long,int>, vector<tuple<long long,int>>, greater<tuple<long long,int>>> pq;
        //dist, index
        
        vector<vector<tuple<int, int>>> adj(N);
        for(auto row: roads){
            adj[row[0]].push_back({row[1], row[2]});    //node2, time
            adj[row[1]].push_back({row[0], row[2]});    //node1, time
        }
        
        const long long MOD = 1e9+7;
        vector<int> ways(N,0);
        vector<long long> timeTaken(N, 1e18);
        
        //Number of ways of reaching source is 1
        ways[0] =1;
        timeTaken[0] =0;
        
        
        pq.push({timeTaken[0], 0});//dust, idx
        
        while(!pq.empty()){
            
            auto [time , vtx] = pq.top(); pq.pop();
            
            
            for(auto &[node, nodeTime]: adj[vtx]){
                
                //current time+ time to reach node
                if(time + nodeTime < timeTaken[node]){
                    //found a Smaller - update
                    timeTaken[node] = time + nodeTime;
                    ways[node] = ways[vtx];
                    
                    pq.push({timeTaken[node], node});
                    
                }else if(time + nodeTime == timeTaken[node]){
                    //found another path with same time
                    ways[node] = (ways[node] + ways[vtx]) %MOD;
                }
                
                
            }
            
            
        }
        
        /*for(int ele: dist){
            cout<<ele<<" ";
        }cout<<endl;
        
        for(int ele: ways){
            cout<<ele<<" ";
        }cout<<endl;*/
        
        return ways[N-1];
        
    }
};