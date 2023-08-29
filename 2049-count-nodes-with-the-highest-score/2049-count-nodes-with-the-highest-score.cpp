class Solution {
public:
    
    int dfs(vector<vector<int>> &adj, int node, vector<long long int> &score){
        
        int N = score.size();
        long long int prod =1, sz=0;
        for(int child: adj[node]){
            
            //size of subtree
            int size = dfs(adj, child, score);
            
            prod *= size;
            sz+= size;
            
        }
        
        prod *= (N-sz-1==0)?1:N-sz-1;
        
        score[node] = prod;
        
        
        return sz+1;
        
    }
    
    int countHighestScoreNodes(vector<int>& parents) {
        
        int N = parents.size();
        vector<long long int> score(N, 0);
        
        vector<vector<int>> adj(N, vector<int> ());
        for(int i=0; i<N; i++){
            
            if(parents[i]==-1)
                continue;
            
            adj[parents[i]].push_back(i);
        }
        
        dfs(adj, 0, score);
        
        long long int MAXX=INT_MIN;
        int maxCount = -1;
        
        for(int i=0; i<N; i++){
        
        //    cout<<score[i]<<" ";
            
            if(score[i]>MAXX){
                MAXX= score[i];
                maxCount=1;
            }else if(score[i]==MAXX){
                maxCount++;
            }
            
        }
        
        //cout<<endl;
        return maxCount;
    }
};