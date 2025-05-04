// Single Dijkstra
// Time: O(ElogN)
// Space: O(N)

class Solution {
    using GraphT = std::vector<std::vector<std::pair<int, int>>>;
public:
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        static const long long MAX = 1e10 + 1;
        GraphT graph(n);
        for(const auto &e: edges){
            graph[e[0]].emplace_back(e[1], e[2]);
        }
        
        const auto simultaneous_dijkstra = [&](){
            std::vector<std::vector<long long>> min_dist(3, std::vector<long long>(n, MAX));
            std::priority_queue<tuple<long long, int, int>> pq;
            pq.emplace(0, 0, src1);
            pq.emplace(0, 1, src2);
            while(!pq.empty()){
                const auto [dist, type, node] = pq.top();
                pq.pop();
                if(min_dist[type][node] != MAX){  // already visited
                    continue;
                }
                min_dist[type][node] = -dist;
                if(type <= 1){ // type 1 or type 2
                    if(min_dist[1 - type][node] != MAX){ // make itself a type-3 node
                        pq.emplace(-min_dist[0][node] - min_dist[1][node], 2, node);
                    } 
                    for(const auto &[next_node, edge]: graph[node]){
                        pq.emplace(dist - edge, type, next_node);
                    }
                } else{ // type 3
                    if(node == dest){
                        return -dist;
                    }
                    for(const auto &[next_node, edge]: graph[node]){
                        pq.emplace(dist - edge, 2, next_node);
                    }
                }
            }
            return -1ll;
        };
        
        return simultaneous_dijkstra();
    }
};