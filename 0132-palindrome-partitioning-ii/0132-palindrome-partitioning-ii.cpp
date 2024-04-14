class Solution {
public:
    
    int ispalindrome(int i, int j, string &str, vector<vector<int>> &palin) {

        if(palin[i][j]!=-1)
            return palin[i][j];
        
        int ii=i, jj=j;
          while (i<=j) {

              if(str[i] != str[j])
                return palin[i][j]=false;

            i++; j--;

          }

          return  palin[ii][jj]=true;
    }

    /*int recur(int idx, string &str, vector<int> &memo) {

        if(idx==str.size())
            return 0;

        if(memo[idx]!=-1)
            return memo[idx];

        int minnPart = INT_MAX;
        for (int i= idx; i<str.size(); i++) {

            int part =0;
            if (ispalindrome(idx, i, str)) {
                int part = 1+ recur(i+1, str, memo);
                minnPart = min(part, minnPart);
            }

        }


        return memo[idx] = minnPart;
    }*/
    
    int bottomUp(string &str, vector<vector<int>> &palin) {

        int N = str.size();
        vector<int> dp(N+1, INT_MAX);

        //Base 
        dp[N] = 0;

        for (int i=N-1; i>=0; i--) {

            for (int j=i; j<N; j++) {

                if (ispalindrome(i, j, str, palin)) {
                    dp[i] = min(dp[i], 1+dp[j+1]); 
                }
            }//for j
        }//for i

        return dp[0]-1;
    }
    
    
    
    int minCut(string str) {
        
        //1. Memoization
        /*int N = str.size();
        vector<int> memo(N, -1);
        
        return recur(0, str, memo)-1;
        */
        
        vector<vector<int>> palin(str.size(), vector<int> (str.size(), -1));
        return bottomUp(str, palin);
        
    }
};