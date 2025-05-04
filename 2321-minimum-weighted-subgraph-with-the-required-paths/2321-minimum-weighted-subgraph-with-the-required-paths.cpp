class Solution {
public:
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
            //A-src1, B-src2, C-dest

            //create adjacency List
            vector<vector<pair<int, int>>> adj(n);
            for(auto edge: edges){  //u,v,w
                    adj[edge[0]].push_back({edge[1], edge[2]});
            }

            auto comp = [](tuple<long long int, int, char> &a, tuple<long long int, int, char> &b){
                //dist, node, type
                
                if(get<0>(a) == get<0>(b))  //when dist are sanme
                    return get<2>(a) > get<2>(b);   //smaller type first //A,B,C

                return get<0>(a) > get<0>(b);   //smaller dist first
            };

            priority_queue<tuple<long long int, int, char>, vector<tuple<long long int, int, char>>, decltype(comp)> pq(comp);
            //dist, node, type

            vector<long long int> distA(n, 1e9);
            vector<long long int> distB(n, 1e9);
            vector<long long int> distC(n, 1e9);

            pq.push(make_tuple(0, src2, 'B'));  //distB[src2] = 0;
            pq.push(make_tuple(0, src1, 'A'));  //distA[src1] = 0;

            while(!pq.empty()){

                auto [dist, node, type] = pq.top(); pq.pop();


                //cout<<dist<<" "<<node<<" "<<type<<endl;

                if(type=='A'){

                    if(distA[node]!=1e9)    //already visited in typeA
                        continue;

                    distA[node] = dist;     //updated the distance

                    //if the current node is already visited by other source(B) path
                    if(distB[node]!=1e9){

                        //if(distA[node]+distB[node] < distC[node]){
                            //distC[node] = distA[node]+distB[node];
                            //cout<<"converting A: "<<distA[node]+distB[node]<<" "<<node<<" "<<'C'<<endl;
                            pq.push(make_tuple(distA[node]+distB[node], node, 'C'));
                        //}
                        //new route of type C start with node dist sum of A + B
                    }//else{

                        for(pair<int, int> neighbour: adj[node]){   //u,w
                            
                            //if(distA[node]+neighbour.second < distA[neighbour.first]){
                                //distA[neighbour.first] = distA[node]+neighbour.second;
                                pq.push(make_tuple(distA[node]+neighbour.second, neighbour.first, 'A'));
                            //}
                        }//for
                    //}


                }else if(type=='B'){

                    if(distB[node]!=1e9)    //already visited in typeA
                        continue;

                    //cout<<dist<<" "<<node<<" "<<type<<endl;

                    distB[node] = dist;     //updated the distance

                    //if the current node is already visited by other source(A) path
                    if(distA[node]!=1e9){

                        //if(distA[node]+distB[node] < distC[node]){
                            //distC[node] = distA[node]+distB[node];
                            //cout<<"converting B: "<<distA[node]+distB[node]<<" "<<node<<" "<<'C'<<endl;
                            pq.push(make_tuple(distA[node]+distB[node], node, 'C'));
                        //}
                        //new route of type C start with node dist sum of A + B
                    }//else{

                        for(pair<int, int> neighbour: adj[node]){   //u,w
                            //cout<<"pushing ..."<<distB[node]+neighbour.second<<" "<<neighbour.first<<" "<<'B'<<endl;
                            //if(distB[node]+neighbour.second < distB[neighbour.first]){
                                //distB[neighbour.first] = distB[node]+neighbour.second;
                                pq.push(make_tuple(distB[node]+neighbour.second, neighbour.first, 'B'));
                            //}
                        }//for
                    //}

                }else{//C

                    //cout<<"C: "<<dist<<", "<<node<<", "<<type<<" :: "<<distC[node]<<endl;
                    if(distC[node]!=1e9)    //already visited in typeC
                        continue;


                    if(node == dest){
                        //cout<<dist<<", "<<dest<<endl;
                        return dist;
                    }

                    distC[node] = dist;

                    for(pair<int, int> neighbour: adj[node]){   //u,w
                        //cout<<"C neigh: "<<distC[neighbour.first]<<endl;
                        //if(distC[node]+neighbour.second < distC[neighbour.first]){
                            //distC[neighbour.first] = distC[node]+neighbour.second;
                            //cout<<"pushing ..."<<distC[node]+neighbour.second<<" "<<neighbour.first<<" "<<'C'<<endl;
                            pq.push(make_tuple(distC[node]+neighbour.second, neighbour.first, 'C'));
                        //}
                    
                    }//for
                }

            }//while

            return -1;
    }
};