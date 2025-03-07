class Solution {
public:
    
    int ispalindrome(string &s, int start, int end) {

          while(start<=end){
            if(s[start++]!=s[end--])
                return false;
        }

          return  true;
    }

    int recur(int idx, string &str, vector<int> &memo) {

        if(idx==str.size())
            return 0;

        if(memo[idx]!=-1)
            return memo[idx];

        int minnPart = INT_MAX;
        for (int i= idx; i<str.size(); i++) {

            int part =0;
            //check if string [start end] is palindrome
            if (ispalindrome(str, idx, i)) {
                int part = 1+ recur(i+1, str, memo);
                minnPart = min(part, minnPart);
            }

        }


        return memo[idx] = minnPart;
    }
    
    
    int bottomUp(string &str) {

        int N = str.size();
        vector<int> dp(N+1, INT_MAX);   
        /*
        dp[i] -> min # cuts needed to partition i-(N-1)
        
        
        if i-j is palindrome then ,
        min cuts needed = 1+dp[j+1]
        dp[i] = 1+ dp[j]
        
        min # cuts needed to partition i-(N-1)
        = 1+ min # cuts needed to partition j+1-(N-1)
        
        i-j is already a plaindrome
        
        
        Base case [N] =0
        */
        dp[N] = 0;

        for (int i=N-1; i>=0; i--) {
            
            int minn = INT_MAX;

            for (int j=i; j<N; j++) {

                if (ispalindrome(str, i, j)) {
                    minn = min(minn, 1+dp[j+1]);
                }
            }//for j
            
            dp[i]=minn;
        }//for i

        return dp[0]-1;
    }
    
    
    
    int minCut(string str) {
        
        //Method 1. Recursion + Memoization    - 1674 ms
//         int N = str.size();
//         vector<int> memo(N, -1);
        
//         return recur(0, str, memo)-1;
        
        
        //Method 2. - 1777ms
        return bottomUp(str);
        
    }
};