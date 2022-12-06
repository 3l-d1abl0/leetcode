class Solution {
public:
    
    bool recur(int idx1, string &s, int N, int idx2, string &p, int M, vector<vector<int>> &memo){
        
        
        if(idx1==N && idx2==M)
                return true;
        
        if(idx2==M && idx1<N)
            return false;


        if(idx1==N && idx2<M){
            for(int i=idx2; i<M; i++){
                if(p[i]!='*')
                    return false;
            }
            return true;
        }
        
        
        if(memo[idx1][idx2]!=-1)
            return memo[idx1][idx2];
        
        bool ans = false;
        
        //cout<<s[idx1]<<" "<<p[idx2]<<endl;
        if (p[idx2]=='*'){
            ans = recur(idx1+1, s, N, idx2, p, M, memo) || recur(idx1, s, N, idx2+1, p, M, memo);
        }else if(s[idx1]==p[idx2] || p[idx2]=='?'){
                ans = recur(idx1+1, s, N, idx2+1, p, M, memo);
        }else{
                //cout<<"NOTEQUAL"<<endl;
                ans = false;
        }
        
            
        
        return memo[idx1][idx2] = ans;
        
    }
    
    bool bottomUp(string &s, int N, string &p, int M){
        
        vector<vector<int>> dp(N+1, vector<int> (M+1, false));
        
        //BaseCases
        dp[N][M] = true;
        
        for(int i=0; i<N; i++)
            dp[i][M] = false;

        /*if(idx1==N){
            for(int i=idx2; i<M; i++){
                if(p[i]!='*')
                    return false;
            }
            return true;
        }*/
        
        for(int i=M-1; i>=0; i--){
            
            bool flag = true;
            
            for(int j=i; j<M; j++){

                if(p[j]!='*'){
                    flag = false;
                    break;
                }

                
            }
            
            dp[N][i] = flag;
        }
        
        for(int i=N-1; i>=0; i--){
            
            for(int j=M-1; j>=0; j--){
                
                if (p[j]=='*'){
                    dp[i][j] = dp[i+1][j] || dp[i][j+1];
                }else if(s[i]==p[j] || p[j]=='?'){
                        dp[i][j] = dp[i+1][j+1];
                }else{
                        dp[i][j] = false;
                }
                
            }
        }
        
        
        return dp[0][0];
        
    }
    
    bool isMatch(string s, string p) {
        
        int N = s.size();
        int M = p.size();
        
        //1. Recursion + Backtracking
        //vector<vector<int>> memo(N, vector<int> (M, -1));
        //return recur(0, s, N, 0, p, M, memo);
        
        
        //2. Botom Up
        return bottomUp(s, N, p, M);
    }
};