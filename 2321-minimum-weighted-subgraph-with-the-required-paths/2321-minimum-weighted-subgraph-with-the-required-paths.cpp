class Solution {
public:

    void dijkstra(int src, vector<long long> &distNode, vector<vector<pair<int, int>>> &adj){

        priority_queue<tuple<long long , int>, vector<tuple<long long, int>>, greater<tuple<long long, int>>> pq;//minHeap
        
        distNode[src] =0;
        pq.push({0, src});


        while(!pq.empty()){

            auto [dist, node] = pq.top(); pq.pop();

            for(auto [to, w] :adj[node]){

                if(distNode[to] >  distNode[node]+w){
                    distNode[to] =  distNode[node]+w;
                    pq.push({distNode[to], to});
                }

            }//for

        }//while


        // for(int val: distNode)
        //     cout<<val<<" ";

        // cout<<endl;


    }//void

    long long threeDijkstra(int n, vector<vector<int>>& edges, int src1, int src2, int dest){

        vector<vector<pair<int, int>>> adj(n), revAdj(n);
        for(auto &edge: edges){
            adj[edge[0]].push_back({edge[1], edge[2]});
            revAdj[edge[1]].push_back({edge[0], edge[2]});
        }

        vector<long long> distA(n, 1e10);
        vector<long long> distB(n, 1e10);
        vector<long long> distD(n, 1e10);

        //distA[src1]=distB[src2]=distD[dest]=0;

        dijkstra(src1, distA, adj);
        dijkstra(src2, distB, adj);
        dijkstra(dest, distD, revAdj);

        long long ans = LLONG_MAX;
        for(int i=0; i<n; i++){
            if(distA[i]== 1e10 || distB[i] == 1e10 || distD[i] == 1e10)
                continue;

            ans = min(ans, distA[i]+distB[i]+distD[i]);
        }

        return (ans ==LLONG_MAX)?-1:ans;
    }

    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        

        //method1 - 3 dijkstras Call
        return threeDijkstra(n, edges, src1, src2, dest);
    }
};