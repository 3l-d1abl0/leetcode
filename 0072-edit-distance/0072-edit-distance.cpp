class Solution {
public:
    /*
    
        Word1 to word2
    */
    
    int editDistanceUtil(string& S1, string& S2, int i, int j, vector<vector<int>>& dp) {
        // Base cases
        if (i < 0)
            return j + 1;
        if (j < 0)
            return i + 1;

        // If the result for this state has already been calculated, return it
        if (dp[i][j] != -1)
            return dp[i][j];

        // If the characters at the current positions match, no operation is needed
        if (S1[i] == S2[j])
            return dp[i][j] = 0 + editDistanceUtil(S1, S2, i - 1, j - 1, dp);

        // Minimum of three choices:
        // 1. Replace the character at S1[i] with the character at S2[j]
        // 2. Delete the character at S1[i]
        // 3. Insert the character at S2[j] into S1
        else
            return dp[i][j] = 1 + min(editDistanceUtil(S1, S2, i - 1, j - 1, dp),
                                      min(editDistanceUtil(S1, S2, i - 1, j, dp),
                                          editDistanceUtil(S1, S2, i, j - 1, dp)));

    }
    
    
    
    int minDistance(string s, string t) {
     
        int N=s.length();
        int M=t.length();
        
        
        vector<vector<int>> memo(N, vector<int>(M, -1));

        // Call the utility function with the last indices of both strings
        return editDistanceUtil(s, t, N - 1, M - 1, memo);
        
        
        vector<vector<int>>dp(N+1,vector<int>(M+1,0));
        
        //cost of converting empty string to o..i
        for(int i=0;i<=N;i++)
            dp[i][0]=i;
        
        //cost of converting empty string to 0..j
         for(int j=0;j<=M;j++)
            dp[0][j]=j;
        
        
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=M;j++)
            {
                if(s[i-1]==t[j-1])
                    dp[i][j]=dp[i-1][j-1]; 
               else
                   dp[i][j]=1+min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
               /*
               1. Idelete at i
               2, Insert at j
               3. replace
               */
           }
       }
       return dp[N][M];
    }
};