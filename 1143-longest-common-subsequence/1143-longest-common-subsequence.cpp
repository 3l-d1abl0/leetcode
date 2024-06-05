class Solution {
public:
    
    int topDown(int idx1, string &str1, int N, int idx2, string &str2, int M, vector<vector<int>> &memo){
        
        if(idx1==N || idx2 == M)
            return 0;
        
        
        if(memo[idx1][idx2]!=-1)
            return memo[idx1][idx2];
        
        int maxLen = 0;
        if(str1[idx1]== str2[idx2]){
            maxLen = 1+ topDown(idx1+1, str1, N, idx2+1, str2, M, memo);
        }else{
            
            maxLen = max( topDown(idx1+1, str1, N, idx2, str2, M, memo),
                      topDown(idx1, str1, N, idx2+1, str2, M, memo) );
        }
        
        return memo[idx1][idx2] = maxLen;
    }
        
    int bottomUp(string str1, int N, string str2, int M){

        vector<vector<int>> dp(N+1, vector<int>(M+1, 0));

        for(int i=1; i<=N; i++){
            for(int j=1; j<=M; j++){

                if(str1[i-1] ==str2[j-1])
                    dp[i][j]= dp[i-1][j-1]+1;
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }


	    return dp[N][M];
        
    }
    
    
    
    int longestCommonSubsequence(string str1, string str2) {
        
        int N = str1.length();
	    int M = str2.length();
        
        //1. Top Down - memoization
        vector< vector<int>> memo(N, vector<int>(M, -1));
        return topDown(0, str1, N, 0, str2, M, memo);
        
        
        //2. Bottom Up - Tabulation
        return bottomUp(str1, N, str2, M);

    }
};