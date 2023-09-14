class Solution {
public:
    
    bool recursion(int idx, int k, unordered_map<int, int> &landing, vector<int> &stones, vector<vector<int>> &mp){
        
        if(idx==stones.size()-1)
            return true;
        
        
        if(mp[idx][k]!=-1)
            return mp[idx][k];
        
        bool ans = false;
        for(int nxtJmp=k-1; nxtJmp <=k+1; nxtJmp++){
            
            if(nxtJmp >0 && landing.find(stones[idx]+nxtJmp)!=landing.end()){
                
                ans |= recursion(landing[stones[idx]+nxtJmp], nxtJmp, landing, stones, mp);
                
            }
            
        }
        
        
        return mp[idx][k] = ans;        
        
    }
    
    
    bool canCross(vector<int>& stones) {
        
        int start = stones[0];
        int target = stones[stones.size()];
        
        
        
        vector<vector<int>> mp(2001, vector<int> (2001, -1));
        
        unordered_map<int, int> landing;
        for(int i=0; i<stones.size(); i++){
            landing.insert({stones[i], i});
        }
        
        return recursion(0, 0, landing, stones, mp);
        
    }
};