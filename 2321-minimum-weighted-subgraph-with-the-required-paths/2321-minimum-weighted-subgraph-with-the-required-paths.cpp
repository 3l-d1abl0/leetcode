class Solution {
public:

    long long simultaneousDijkstra(int n, vector<vector<int>>& edges, int src1, int src2, int dest){

        vector<vector<pair<int, int>>> adj(n);
        for(auto &edge: edges)
            adj[edge[0]].push_back({edge[1], edge[2]});
        
        const auto dijkstra = [&](){

            vector<vector<long long>> distNode(3, vector<long long>(n, 1e10));

            //dist, node, type
            priority_queue<tuple<long long, int, int>, vector<tuple<long long, int, int>>, greater<tuple<long long, int, int>>> pq;//min heap

            pq.emplace(0, src1, 0); distNode[0][src1] = 0;
            pq.emplace(0, src2, 1); distNode[1][src2] = 0;


            while(!pq.empty()){

                auto [dist, node, type] = pq.top(); pq.pop();

                if(distNode[type][node]!= 1e10 && distNode[type][node]!= dist){
                    //cout<<"continuing ... ("<<type<<") :: "<<node<<", "<<distNode[type][node]<<"!= "<<dist<<endl;
                    continue;
                }


                if(type<=1){

                    if(distNode[type^1][node] != 1e10){  //if the other type has visited the node, start a type 'dest' path
                        //cout<<"converting from ("<<type<<") node="<<node<<" dist="<<distNode[type][node]+distNode[type^1][node]<<endl;
                        if(distNode[2][node] > distNode[type][node]+distNode[type^1][node]){

                            distNode[2][node] = distNode[type][node]+distNode[type^1][node];
                            pq.emplace(distNode[type][node]+distNode[type^1][node], node, 2);
                        }
                }

                    //add the neighbour
                    for(const auto &[neigh, weight]: adj[node]){

                        if(distNode[type][neigh] > dist+ weight){
                            distNode[type][neigh] = dist+ weight;
                            pq.emplace(distNode[type][neigh], neigh, type);
                            //cout<<"added ("<<type<<") node="<<neigh<<" dist="<<distNode[type][neigh]<<endl;
                        }
                    }

                }else{//type ==2 , destination
                    //cout<<"("<<type<<") node="<<node<<" dist="<<dist<<endl;

                    if(node == dest)
                        return dist;

                    //add the neighbour
                    for(const auto &[neigh, weight]: adj[node]){

                        if(distNode[type][neigh] > dist+ weight){
                            distNode[type][neigh] = dist+ weight;
                            pq.emplace(distNode[type][neigh], neigh, 2);
                            //cout<<"added ("<<type<<") node="<<neigh<<" dist="<<distNode[type][neigh]<<endl;
                        }
                    }

                }
            }//while

            return -1ll;
        };


        return dijkstra();

    }

    void dijkstra(int src, vector<long long> &distNode, vector<vector<pair<int, int>>> &adj){
        cout<<"src: "<<src<<endl;
        priority_queue<tuple<long long , int>, vector<tuple<long long, int>>, greater<tuple<long long, int>>> pq;//minHeap
        
        distNode[src] =0;
        pq.push({0, src});


        while(!pq.empty()){

            auto [dist, node] = pq.top(); pq.pop();

            if(distNode[node]!= dist){
                cout<<distNode[node]<<" "<<dist<<endl;
                continue;
            }

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
        //return threeDijkstra(n, edges, src1, src2, dest);


        //method2 - simultaneous dijkstra
        return simultaneousDijkstra(n, edges, src1, src2, dest);
    }
};