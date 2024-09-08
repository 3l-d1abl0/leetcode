class Solution {
public:
    
    void bfs(int src, vector<int> &dist,vector<int>& edge){
        
        queue<int> q;
        q.push(src);
        
        dist[src]=0;
        
        while(q.size()>0){
        
            auto p= q.front(); q.pop();
            
            //If node has an edge and its distance has been calculated
            if(edge[p]!=-1 and dist[edge[p]]==INT_MAX){
               q.push(edge[p]);  
               dist[edge[p]]= dist[p]+1;
            }
        }
    };
    
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        
        int N = edges.size();
        
        vector<int> distA(N,INT_MAX), distB(N,INT_MAX);
        
        bfs(node1, distA, edges);
        bfs(node2, distB, edges);
        
        int maxDist= INT_MAX, node=-1;
        for(int i=0;i<N;i++){
            
            if(distA[i]==INT_MAX or distB[i]==INT_MAX)
                continue;
            
            if(maxDist>max(distA[i], distB[i]))
                node=i, maxDist= max(distA[i], distB[i]);
            
        }
        
        return node;
        
        
    }
};