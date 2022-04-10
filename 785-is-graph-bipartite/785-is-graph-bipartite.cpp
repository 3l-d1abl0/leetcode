class Solution {
public:
    bool isBipartite(vector<vector<int>>& adj) {
        
        
        int N = adj.size();
        
        vector<int> color(N, -1);
        
        for(int i=0; i<N; i++){
            
            if(color[i]==-1)
                //if(isBipartiteBFS(i, color, adj)==false)
                color[i]=0;
                if(isBipartiteDFS(i, color, adj)==false)
                    return false;
            
        }
        
        
        return true;
    }
    
    
    bool isBipartiteDFS(int src, vector<int> &color, vector<vector<int>>& adj){
        
        for(int ele: adj[src]){
            
            if(color[ele]!=-1){
                if(color[ele]==color[src])
                    return false;
            }else{
                
                color[ele] = 1- color[src];
                
                if(isBipartiteDFS(ele, color, adj)==false)
                    return false;
                
            }
            
        }
        
        
        return true;
        
        
    }
    
    bool isBipartiteBFS(int src, vector<int> &color, vector<vector<int>>& adj){
        
        color[src] =0;
        
        queue<int> q;
        q.push(src);
        
        
        
        while(!q.empty()){
            
            int vtx = q.front(); q.pop();
            
            for(int ele: adj[vtx]){
                
                if(color[ele]==-1){
                    
                    color[ele] = 1- color[vtx];
                    
                    q.push(ele);
                    
                    
                }else{
                    
                    if(color[ele] == color[vtx])    return false;
                    
                }
                
            }
            
        }
        
        return true;
    }
    
};