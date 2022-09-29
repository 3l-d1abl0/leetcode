class Solution {
public:
    
    bool isPalin(int beg, int en, string &s){
        
        while(beg<en){
            if(s[beg++]!=s[en--])
                return false;
        }
        return true;
    }
    
    int minpart(int idx, string &s, vector<int> &memo){
        
        if(idx==s.size())
            return 0;
        
        if(memo[idx]!=-1)
            return memo[idx];
        
        int minn = INT_MAX;
        for(int i=idx; i<s.size(); i++){
            
            if(isPalin(idx, i, s)){
                
                minn = min(minn, minpart(i+1,s, memo)+1);
            }
        }
        
        return memo[idx]=minn;
        
    }
    
    int minCut(string s) {
        
        
        vector<int> memo(s.size(), -1);
        return minpart(0, s, memo)-1;
    }
};