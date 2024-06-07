class Solution {
public:
    
    bool recur(int sidx, string &s, int N, int pidx, string &p, int M, vector<vector<int>> &memo){
        
        
        //Both have been exhausted
        if(sidx==0 && pidx==0)
                return true;
        
        //pattern has exhausted but string hasnt
        if(sidx>0 && pidx==0)
            return false;

        
        //String has finished but we have remaining pattern
        //just check if it is * or not
        if(sidx==0 && pidx>0){
            
            for(int i=pidx; i>=1; i--){
                if(p[i-1]!='*')   //stop if is not a *
                    return false;
            }
            return true;
        }
        
        
        if(memo[sidx][pidx]!=-1)
            return memo[sidx][pidx];
        
        bool ans = false;
        
        
        
        if (p[pidx-1]=='*'){  //match one | doesnt match
            ans = recur(sidx-1, s, N, pidx, p, M, memo) || recur(sidx, s, N, pidx-1, p, M, memo);
        }else if(s[sidx-1]==p[pidx-1] || p[pidx-1]=='?'){
                ans = recur(sidx-1, s, N, pidx-1, p, M, memo);
        }else{
                //cout<<"NOTEQUAL"<<endl;
                ans = false;
        }
        
            
        
        return memo[sidx][pidx] = ans;
        
    }
    
    
    
    bool bottomUp(string &s, int N, string &p, int M){
        
        vector<vector<bool>> dp(N+1, vector<bool> (M+1, false));
        
        //both readched end
        //BaseCases
        dp[0][0] = true;
        
        //pattern has ended but string is not
        for(int sidx=1; sidx<=N; sidx++)
            dp[sidx][0] = false;

        
        //String has finished but we have remaining pattern
        //just check if it is * or not
        //for every sidx ==0 && pattern index > 0, check if its * or not
        bool status = true;
        for(int pidx=1; pidx<=M; pidx++){
            if(p[pidx-1]!='*')   //stop if is not a *
                status = false;

            dp[0][pidx] = status;
        }
        
        
        
        for(int i=1; i<=N; i++){
            
            for(int j=1; j<=M; j++){
                
                if (p[j-1]=='*'){
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                }else if(s[i-1] == p[j-1] || p[j-1]=='?'){
                        dp[i][j] = dp[i-1][j-1];
                }else{
                        dp[i][j] = false;
                }
                
            }
        }
        
        
        //print(dp);
        
        return dp[N][M];
        
    }
    
    void print(vector<vector<bool>> &dp){


        for(auto row: dp){
            for(int ele: row){
                cout<<ele<<" ";
            }
            cout<<endl;
        }
    }
    
    bool isMatch(string s, string p) {
        
        int N = s.size();
        int M = p.size();
        
        //1. Recursion + Backtracking - topDown
        vector<vector<int>> memo(N+1, vector<int> (M+1, -1));
        return recur(N, s, N, M, p, M, memo);
        
        
        //2. Botom Up
        return bottomUp(s, N, p, M);
    }
};