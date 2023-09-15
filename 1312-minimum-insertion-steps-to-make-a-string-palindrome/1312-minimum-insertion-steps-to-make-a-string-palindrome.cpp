class Solution {
public:
    
    int LCS(string &str1, string &str2){
        
        int N = str1.length();
	    int M = str2.length();        
        
        
        
        vector<vector<int>> dp(N+1, vector<int> (M+1, 0));
        
        //Base case - all M is 0
        for(int idx1=0; idx1<=N; idx1++)
            dp[idx1][0] =0;
        
        //base case all N is 0
        for(int idx2=0; idx2<=M; idx2++)
            dp[0][idx2] =0;
        
        
        
        
        for(int idx1= 1; idx1<=N; idx1++){
            
            for(int idx2=1; idx2<=M; idx2++){
            
                if(str1[idx1-1] == str2[idx2-1]){
                    
                    dp[idx1][idx2] = 1+ dp[idx1-1][idx2-1];
                    
                }else{
                    dp[idx1][idx2] = max(dp[idx1-1][idx2], dp[idx1][idx2-1]);
                }
                    
            }
        }//for
        
        
        return dp[N][M];
        
    }
    
    int LPS(string &s){
        
        string rev = s;
        reverse(s.begin(), s.end());        
        return LCS(s, rev);
    }
    
    int minInsertions(string s) {
     
        /*
            Find the longes palindromic subsequence,
            find the rest of the characters.
            If you delete those characters string becomes palindrome.
            If you insert those characters in the stringm, yo can make it Palindrome.
            
            Hence those are the min number of insertion.
        
        */
        
        return s.size() - LPS(s);
    }
};