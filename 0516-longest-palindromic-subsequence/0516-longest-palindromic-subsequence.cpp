class Solution {
public:
    
    int topDown(string &str1, string &str2){
        
        int N = str1.length();
	    int M = str2.length();        
        
        
        
        vector<vector<int>> dp(N+1, vector<int> (M+1, 0));
        
        //Base case - all M is 0
        /*for(int idx1=N-1; idx1>=0; idx1--)
            dp[idx1][M] =0;
        
        //base case all N is 0
        for(int idx2=M-1; idx2>=0; idx2--)
            dp[N][idx2] =0;
        */
        
        
        for(int idx1= N-1; idx1>=0; idx1--){
            
            for(int idx2=M-1; idx2>=0; idx2--){
            
                if(str1[idx1] == str2[idx2]){
                    
                    dp[idx1][idx2] = 1+ dp[idx1+1][idx2+1];
                    
                }else{
                    dp[idx1][idx2] = max(dp[idx1+1][idx2], dp[idx1][idx2+1]);
                }
                    
            }
        }//for
        
        
        return dp[0][0];
        
    }
    
    int longestPalindromeSubseq(string s) {
    
        
        string s2 = s;
        reverse(s2.begin(), s2.end());
        
        return topDown(s, s2);
    }
};