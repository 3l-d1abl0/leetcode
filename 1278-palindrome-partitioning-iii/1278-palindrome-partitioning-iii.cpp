class Solution {
public:
    
    int cost(string& s, int i, int j, vector<vector<int>> &palin){
        
        if(i >= j) return 0;
        if(palin[i][j] != -1)
            return palin[i][j];
        
        return palin[i][j] = (s[i] != s[j]) + cost(s, i+1, j-1, palin);
    }
    
    int palindromeCost(int i, int j, string &s){
        
        int replace =0;
        
        while(i<=j){
            
            if(s[i]!=s[j])
                replace ++;
            
            i++; j--;
        }
    
        return replace;
    }
    
    int recur(int idx, int part, string &s, int k, vector<vector<int>> &memo, vector<vector<int>> &palin){
        
        //1 more cut remaining
        //insted of making cuts at several index
        //just calculate the cost of the remaingin string
        if(part==k-1){
            
            //cant make one more cut
            if(idx==s.size())
                return 1e7;
            
            //int ans = palindromeCost(idx, s.size()-1, s);
            int ans = cost(s, idx, s.size()-1, palin);
            return ans;
        }
        
        if(idx==s.size()) return 1e7;
        
        
        if(memo[idx][part]!=-1)
            return memo[idx][part];
        
        int ans = 1e7;
        for(int i=idx; i<s.size(); i++){
            
            //int tmpCost = palindromeCost(idx, i, s);
            int tmpCost = cost(s, idx, i, palin);
            int recCost = recur(i+1, part+1, s, k, memo, palin);
            
            
            ans = min(ans, tmpCost+recCost);
        }
        
        return memo[idx][part] = ans;
    }
    
    int palindromePartition(string s, int k) {
        
        
        //1. Memoization
        
        vector<vector<int>> palin(s.size(), vector<int>(s.size(), -1));
        vector<vector<int>> memo(s.size(), vector<int>(k, -1));
        return recur(0, 0, s, k, memo, palin);
    }
};