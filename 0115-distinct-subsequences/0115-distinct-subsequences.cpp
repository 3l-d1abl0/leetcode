class Solution {
public:
    
    void print2D(vector<vector<int>> &dp, string msg){
        
        cout<<msg<<endl;
        
        for(auto row: dp){
            for(int ele: row){
                cout<<ele<<" ";
            }
            
            cout<<endl;
        }
        
    }
    
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
    
    int bottomUp(string &s, int N, string &t, int M){
        
        vector<vector<double>> dp(N+1, vector<double>(M+1, 0));
        
        //base cases
        //all idx ==M =1
        
        /*for(int idx2 =0 ; idx2<=M; idx2++ ){
            dp[N][idx2] =0;
        }*/
        
        for(int idx1=0; idx1<=N; idx1++){
            dp[idx1][M] =1;
        }
        
        //rint2D(dp,"1.");
        //cout<<"------"<<N+1<<M+1<<endl;
        for(int idx1 = N-1; idx1>=0; idx1--){
            
            for(int idx2= M-1; idx2>=0; idx2--){
                
                //1.exclude /skip
                dp[idx1][idx2] = dp[idx1+1][idx2];
                
                //2. Include
                if(s[idx1]==t[idx2])
                    dp[idx1][idx2] += dp[idx1+1][idx2+1];
                
            }
        }
        
        //print2D(dp,"2.");
        return dp[0][0];
        
    }
    
    int numDistinct(string s, string t) {
        
        int N = s.size();
        int M = t.size();
        
        //1. recursion + memo
        //vector<vector<int>> memo(N, vector<int> (M, -1));
        //return recur(0, s, N, 0, t, M, memo);
        
        
        //2. Bottom Up DP
        return bottomUp(s, N, t, M);
        
    }
};