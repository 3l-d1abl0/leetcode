class Solution {
public:

    void solve(int src,unordered_map<int,list<int>> &adjList,int parent,int &timer,vector<int> &tin,vector<int> &low,unordered_map<int,bool> &visited,vector<vector<int>> &ans){
        visited[src] = true;
        tin[src] = timer;
        low[src] = timer;
        timer++;

        for(int nbr:adjList[src]){
            if(nbr == parent){
                continue;
            }
            if(!visited[nbr]){
                solve(nbr,adjList,src,timer,tin,low,visited,ans);
                low[src] = min(low[src],low[nbr]);
                // checking bridge is there or not:
                if(low[nbr] > tin[src]){
                    vector<int> temp;
                    temp.push_back(src);
                    temp.push_back(nbr);
                    ans.push_back(temp);
                }
            }else{
                low[src] = min(low[src],low[nbr]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        // adjList;
        unordered_map<int,list<int>> adjList;
        for(vector<int> v:connections){
            adjList[v[0]].push_back(v[1]);
            adjList[v[1]].push_back(v[0]);
        }
        // traverse tin = 1 increement in each !visited node.
        int timer = 1;
        vector<int> tin(n,0);
        vector<int> low(n,0);
        vector<vector<int>> ans;
        int src = 0;
        int parent = -1;
        unordered_map<int,bool> visited;

        solve(src,adjList,parent,timer,tin,low,visited,ans);

        return ans;
        // give low  = tin in every unvisited node
        // update low for every node
        // during backtracking check the bridge.
        // if there push the u,v in ans. vector.
    }
};