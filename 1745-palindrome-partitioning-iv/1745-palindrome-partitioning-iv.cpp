class Solution {
public:
    
    int ispalindrome(int i, int j, string &str) {

          while (i<=j) {

              if(str[i] != str[j])
                return false;

            i++; j--;

          }

          return  true;
    }
    
    
    int ispalindromeRec(int i, int j, string &str, vector<vector<int>> &palin) {

        if(i>j)
            return 0;
        
        if(i==j)
            return 1;
        
        if(abs(i-j)==1)
            return str[i] == str[j];
        
        if(palin[i][j]!=-1)
            return palin[i][j];
        

        if(str[i] != str[j])
                return palin[i][j] = false;

        
        return palin[i][j]=ispalindromeRec(i+1, j-1, str, palin);


    }
    

    int recur(int idx, int part, string &str, int K, vector<vector<int>> &memo, vector<vector<int>> &palin) {

        //1 partition remaining - char if its palin
        if(part==K-1){
            
            //If partition cannot be made
            if(idx==str.size())
                return false;
            
            return ispalindromeRec(idx, str.size()-1, str, palin);
            //return ispalindrome(idx, str.size()-1, str);
        }
        
        
        if(idx==str.size())
            return false;

        if(memo[idx][part]!=-1)
            return memo[idx][part];

        int made = false;
        for (int i= idx; i<str.size(); i++) {

            if(ispalindromeRec(idx, i, str, palin)){
            //if (ispalindrome(idx, i, str)) {
                made = made || recur(i+1, part+1, str, K, memo, palin);
            }

        }


        return memo[idx][part] = made;
    }
    
    
    int bottomUp(string &s, int K){
        
        int N = s.size();
        
        //Precompute the palindrome Table
        vector<vector<int>> palin(N, vector<int> (N, false));
        
            //palindrome of 1 length
            for(int i=0; i<N; i++)
                palin[i][i] =true;

            //palindrome of 2 length
            for(int i=0; i<N-1; i++){
                if(s[i]!=s[i+1])
                    palin[i][i+1] =false;
                else
                    palin[i][i+1] =true;

            }
            //palindrome of length 3 and above
            for(int len=3; len<=N; len++){

                for(int j=0; j<N; j++){

                    if(j+len-1>= N)
                        continue;

                    int k = j+len-1;
                    if(s[j]!=s[k])
                        palin[j][k] = false;
                    else
                        palin[j][k] = palin[j+1][k-1];
                }
            }
        
            vector<vector<int>> dp(N+1, vector<int> (K, false));
            
            //Base Case 1
            for(int i=0; i<N; i++)
                dp[i][K-1] = palin[i][N-1];
            //Base Case 2
            for(int j=0; j<=K-1; j++)
                dp[N][j] = false;
        
            
            for(int idx=N-1; idx>=0; idx--){
                
                
                for(int part =K-2; part>=0; part--){
                    
                    
                    int made = false;
                    for(int i=idx; i<N; i++){
                        
                        if(palin[idx][i])
                            made = made || dp[i+1][part+1];
                    }
                    
                    dp[idx][part] = made;
                }
            }//for idx
        
        
        return dp[0][0];
    }
    
    bool checkPartitioning(string str) {
     
        //1. Memoization
        /*int K = 3;
        int N = str.size();
        vector<vector<int>> memo(N, vector<int> (K, -1));
        vector<vector<int>> palin(N, vector<int> (N, -1));
        
        return recur(0, 0, str, K, memo, palin);
        */
        
        
        //2. BottomUp
        return bottomUp(str, 3);
        
    }
};