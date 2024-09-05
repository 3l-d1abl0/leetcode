class Solution {
public:
    
    void dfs(int city, int &newEdges, vector<vector<int>> &adj, unordered_set<string> &neiCity, vector<bool> &visited){
        
        visited[city] = true;
        
        
        for(int neigh: adj[city]){
            
            if(visited[neigh] == true)
                continue;
            
            //is there is an edge from neighbour to current city
            if( neiCity.find( to_string(neigh)+"#"+to_string(city) ) == neiCity.end())
                newEdges++;
            
            dfs(neigh, newEdges, adj, neiCity, visited);
        }
    }
    
    int minReorder(int n, vector<vector<int>>& connections) {
        /*
            Start from the Source and move radially Outward
            
            When at any node, it means we have computed its way from the Capital City
        */
        
        vector<vector<int>> adj(n, vector<int>());
        unordered_set<string> neiCity;  //set of edges from neighbour to city
        for(auto row: connections){
            neiCity.insert( to_string(row[0])+"#"+to_string(row[1]) );
            
            adj[row[0]].push_back(row[1]);
            adj[row[1]].push_back(row[0]);
        }
        
        vector<bool> visited(n, false);
        int newEdges =0;
        dfs(0, newEdges, adj, neiCity, visited);
        
        return newEdges;
    }
};