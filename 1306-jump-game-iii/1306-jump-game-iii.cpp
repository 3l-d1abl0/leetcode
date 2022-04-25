class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        
        
        int N= arr.size();
        
        vector<bool> vis(N, false);
        
        queue<int> q;
        
        q.push(start);
        
        vis[start] =true;
        
        
        while(!q.empty()){
            
            int idx = q.front(); q.pop();
            
            if(arr[idx]==0)
                return true;

            //+
            int new_idx = idx+arr[idx];
            if(new_idx>=0 && new_idx<=N-1 && vis[new_idx]==false){
                q.push(new_idx);
                vis[new_idx] = true;
            }
            
            new_idx = idx-arr[idx];
            if(new_idx>=0 && new_idx<=N-1 && vis[new_idx]==false){
                q.push(new_idx);
                vis[new_idx] = true;
            }
            
        }
        
        
        return false;
    }
};