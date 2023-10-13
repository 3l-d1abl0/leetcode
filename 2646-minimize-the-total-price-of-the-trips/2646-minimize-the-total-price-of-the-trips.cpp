class Solution {
public:
    
    void bfs(vector<vector<int>> &adj, int u, int v, vector<int> &parent){
        
        parent[u] = -1;
        
        queue<pair<int, int>> q;
        
        q.push({u, -1});
        
        while(!q.empty()){
            
            auto node = q.front();
            q.pop();
            
            if(node.first == v){
                break;
            }
            
            for(int neigh: adj[node.first]){
                
                if(neigh == node.second)
                    continue;
                
                q.push({neigh, node.first});
                parent[neigh] = node.first;
                
            }
        }//while
        
        
    }
    
    
    int pick(vector<int> &price, vector<int> &count, vector<vector<int>> &adj, map<pair<int, bool>, int> &mp, int u, int parent, bool parentTaken){
        
        
        if (mp.find({u, parentTaken}) != mp.end())
            return mp[{u, parentTaken}];
        
        
        
            
            if(parentTaken){    //if parent was taken
                
                int cost = count[u] * price[u];
                for(int neigh: adj[u]){
                    
                    if(neigh==parent) continue;
                    
                    //do not half the curernt node
                    cost+=pick(price, count, adj, mp, neigh, u, false);
                }
                
                
                return mp[{u, parentTaken}] = cost;
                
            }else{
                
                
                int cost1 = count[u] * price[u];
                int cost2 = count[u] * (price[u]/2);
                for(int neigh: adj[u]){
                    
                    if(neigh==parent)   continue;
                    
                    
                    //case1: dont half the current node
                    cost1 +=pick(price, count, adj, mp, neigh, u, false);
                    
                    
                    //case2: half the curretn node
                    cost2 +=pick(price, count, adj, mp, neigh, u, true);
                    
                    
                }//for
                
                
                return mp[{u, parentTaken}] = min(cost1, cost2);
            }
            
            
            
        
    }
    
    int minimumTotalPrice(int n, vector<vector<int>>& edges, vector<int>& price, vector<vector<int>>& trips) {
        
        /*
        
        Similar to House Robber - III
        */
        
        //Make adj Graph
        vector<vector<int>> adj(n, vector<int> ());
        
        for(auto row: edges){
            adj[row[0]].push_back(row[1]);
            adj[row[1]].push_back(row[0]);
        }
        
        vector<int> count(n, 0);
        //Find path of each trip and modify occurances
        for(auto row: trips){
            
            vector<int> parent(n, -1);
            bfs(adj, row[0], row[1], parent);
            
            
            int curr = row[1];
            while(curr!=-1){

                count[curr]++; curr= parent[curr];
            }
            
        }
        
        
        //Considering 0 as the root
        map<pair<int, bool>, int> mp;
        return min( pick(price, count, adj, mp, 0, -1, true), pick(price, count, adj, mp, 0, -1, false) );
        
        
        return -1;
    }
};