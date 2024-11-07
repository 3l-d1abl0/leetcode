class Solution {
public:
    void printVec(vector<int> &nodeColor){
        for(auto ele: nodeColor) cout<<ele<<" ";
        
        cout<<endl;
    }
    
    bool safe(int idx, int color, vector<int> &nodeColor, vector<vector<int>> &adjList){
        
        for(int neighbour = 0; neighbour<adjList[idx].size(); neighbour++){
            
            if( nodeColor[adjList[idx][neighbour]-1] == color )
                return false;
            
        }
        
        return true;
        
    }
    
    bool solve(int idx, int totalNodes, vector<int> &nodeColor, vector<vector<int>> &adjList){
        
            //cout<<"idx :: "<<idx<<endl;
            
            if(idx > totalNodes)
                return true;
        
            //4 Types of Flower
            int colorType = 4;
        
        
            for(int color=1; color <=colorType; color++){
                
                //cout<<"Safe ?"<<idx<<" :: "<<color<<endl;
                if(safe(idx, color, nodeColor, adjList)){ 
                    
                    nodeColor[idx-1] = color;
                    
                    //printVec(nodeColor);
                    
                    if(solve(idx+1, totalNodes, nodeColor, adjList))
                        return true;
                    
                    nodeColor[idx-1] = 0;
                }
                
                
            }
        
        
        return false;
    }
    
    
    vector<int> gardenNoAdj(int nodes, vector<vector<int>>& paths) {
     
        vector<vector<int>> adjList (nodes+1);
        
        
        //Create adj list from the edges
        for(int i=0; i<paths.size(); i++){
            adjList[paths[i][0]].push_back(paths[i][1]);
            adjList[paths[i][1]].push_back(paths[i][0]);
        }
        //default color - 0
        vector<int> nodeColor(nodes, 0);
        
        //start with node 1
        solve(1, nodes, nodeColor, adjList);
        
        return nodeColor;
        
    }
};