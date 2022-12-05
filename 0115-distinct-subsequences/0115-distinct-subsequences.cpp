class Solution {
public:
    
    int recur(int idx1, string &s, int N, int idx2, string &t, int M, vector<vector<int>> &memo){
        
        if(idx2==M) return 1;
        if(idx1==N) return 0;
        
        if(memo[idx1][idx2]!=-1)
            return memo[idx1][idx2];
        
        //skip this - OR this does not match
        int exclude = recur(idx1+1, s, N, idx2, t, M, memo);
        int include = 0;
        
        
        if(s[idx1]==t[idx2]){
            
            include = recur(idx1+1, s, N, idx2+1, t, M, memo);
        }
        
        
        return memo[idx1][idx2] = include + exclude;
    }
    
    int numDistinct(string s, string t) {
        
        int N = s.size();
        int M = t.size();
        
        //1. recursion + memo
        vector<vector<int>> memo(N, vector<int> (M, -1));
        return recur(0, s, N, 0, t, M, memo);
    }
};