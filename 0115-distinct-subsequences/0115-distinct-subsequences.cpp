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
    
    int recur(int idx1, string &s, int idx2, string &t, vector<vector<int>> &memo){
        
        //the pattern has ended
        if(idx2==0) return 1;
        
        //the string has ended
        if(idx1==0) return 0;
        
        if(memo[idx1][idx2]!=-1)
            return memo[idx1][idx2];
        
        //skip this - OR this does not match
        int ans = 0;
        
        
        if(s[idx1-1]==t[idx2-1]){
            /*
                1. move on to the next character in both the sring
                2. move onto the next char in the String (basicall look fo the next occurance)
            */
            int matches = recur(idx1-1, s, idx2-1, t, memo) + recur(idx1-1, s, idx2, t, memo);
            ans = matches;
            
        }else{
            //move to the next char in the String
            int doesNot = recur(idx1-1, s, idx2, t, memo);
            ans = doesNot;
        }
        
        
        return memo[idx1][idx2] = ans;
    }
    
    int bottomUp(string &s, int N, string &t, int M){
        
        vector<vector<double>> dp(N+1, vector<double>(M+1, 0));
        
        //base cases
        //all idx ==M =1
        
        //When string goes empty
        for(int idx2=0; idx2<=M; idx2++)
            dp[0][idx2] = 0;
        
        //WHen pattern goes empty
        for(int idx1=0; idx1<=N; idx1++){
            dp[idx1][0] =1;
        }
        
        //rint2D(dp,"1.");
        //cout<<"------"<<N+1<<M+1<<endl;
        for(int idx1 = 1; idx1<=N; idx1++){
            
            for(int idx2= 1; idx2<=M; idx2++){
                
                //1. Include+skip
                if(s[idx1-1]==t[idx2-1]){
                    dp[idx1][idx2] = dp[idx1-1][idx2-1]+dp[idx1-1][idx2];
                }else{  //2. skip
                    dp[idx1][idx2] = dp[idx1-1][idx2];
                }
                
            }
        }
        
        //print2D(dp,"2.");
        return dp[N][M];
        
    }
    
    int numDistinct(string s, string t) {
        
        /*
            Basically, you have to check in how many ways t is a
            subsequence in s
        */
        
        int N = s.size();
        int M = t.size();
        
        //1. recursion + memo (topDown)
        vector<vector<int>> memo(N+1, vector<int> (M+1, -1));
        return recur(N, s, M, t, memo);
        
        
        //2. Bottom Up DP
        //return bottomUp(s, N, t, M);
        
    }
};