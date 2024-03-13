class Solution {
public:
    
        int dfs(int i, vector<vector<int>> &graph, vector<int> &isSafe){
        
            //if already decided
        if(isSafe[i] != -1) return isSafe[i];
        
        isSafe[i] = 2;  //consider it unsafe
        
        for(int node : graph[i]){
            
            if(dfs(node, graph, isSafe)==2){
                return 2;
            }
            
        }
        
        //if its not unsafe, its safe
        return isSafe[i] =1;
        
        
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        int N = graph.size();
        
        vector<int> isSafe(N, -1);
        vector<int> safe;
        
        /* -1 not decided
            1 - safe
            2- unsafe
        */
        
        for(int i=0; i<N; i++){
            
            if(dfs(i, graph, isSafe)==1){
                safe.push_back(i);        
            }
            
        }
                
        
        return safe;
        
    }
    
    
};