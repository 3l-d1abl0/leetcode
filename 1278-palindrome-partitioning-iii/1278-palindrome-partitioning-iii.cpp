class Solution {
public:
    
    int costPalin(string& s, int i, int j, vector<vector<int>> &palin){
        
        if(i >= j) return 0;
        if(palin[i][j] != -1)
            return palin[i][j];
        
        return palin[i][j] = (s[i] != s[j]) + costPalin(s, i+1, j-1, palin);
    }
    
    int palindromeCost(int i, int j, string &s){
        
        int replace =0;
        
        while(i<=j){
            
            if(s[i]!=s[j])
                replace ++;
            
            i++; j--;
        }
    
        return replace;
    }
    
    int recur(int idx, int part, string &s, int k, vector<vector<int>> &memo, vector<vector<int>> &palin){
        
        //1 more cut remaining
        //insted of making cuts at several index
        //just calculate the cost of the remaingin string
        if(part==k-1){
            
            //cant make one more cut
            if(idx==s.size())
                return 1e7;
            
            //int ans = palindromeCost(idx, s.size()-1, s);
            //Just check if the rest of the string can be made palindrome at What cost
            int ans = costPalin(s, idx, s.size()-1, palin);
            return ans;
        }
        
        if(idx==s.size())
            return 1e7;
        
        
        if(memo[idx][part]!=-1)
            return memo[idx][part];
        
        int ans = 1e7;
        for(int i=idx; i<s.size(); i++){
            
            //int tmpCost = palindromeCost(idx, i, s);
            int tmpCost = costPalin(s, idx, i, palin);//The cost of turning idx - i to a palindrome
            int recCost = tmpCost + recur(i+1, part+1, s, k, memo, palin);
            
            
            ans = min(ans, recCost);
        }
        
        return memo[idx][part] = ans;
    }
    
    int bottomUp(string &s, int K){
        
        int N = s.size();
        vector<vector<int>> palin(N, vector<int>(N, 1e7));
        
        //calculate palindrome cost - table
        for(int i=0; i<N; i++)
            palin[i][i] =0; //same indices no cost
        
        //palindrome of consequtive 2 length
        for(int i=0; i<N-1; i++){
            if(s[i]!=s[i+1])
                palin[i][i+1] =1;//cost
            else
                palin[i][i+1] =0;//no cost
            
        }
        //palindrome of length 3 and above
        for(int len=3; len<=N; len++){
            
            for(int j=0; j<N; j++){
                
                if(j+len-1>= N)
                    continue;
                
                int k = j+len-1;
                if(s[j]!=s[k])
                    palin[j][k] = palin[j+1][k-1] +1;
                else
                    palin[j][k] = palin[j+1][k-1];
            }
        }
        
        ///////////////////////////N+1 x K
        vector<vector<int>> dp(N+1, vector<int>(K, -1e6));
        //base case idx ==N
        for(int j=0; j<K; j++)
            dp[N][j] = 1e7;
        
        /*  Last partition
            When putting the last cut at i
            cost to convert i-(N-1) to palindrome
        */
        for(int i=0; i<N; i++)
            dp[i][K-1] = palin[i][N-1];
        
        
        for(int idx=N-1; idx>=0; idx--){
                
            for(int part=K-2; part >=0; part--){
                
                int ans = 1e7;
                for(int i=idx; i<N; i++){
                    
                    int recCost = dp[i+1][part+1] + palin[idx][i];
                    
                    
                    ans = min(ans, recCost);
                }
                
                dp[idx][part] = ans;
            }
        }
        
        
        return dp[0][0];
        
    }
    
    int palindromePartition(string s, int k) {
        
        
        //1. Memoization - 3ms - 8.3MB
        /*
          Space Complexity:

            palin table: O(n^2)
            memo table: O(n. k)
            Recursive Stack: O(k) depth of recursion of k


            Total Space Complexity: O(n^2 + n.k)  
        */
        //stores the minimum changes needed to make [i j] into a palindrome
        // vector<vector<int>> palin(s.size(), vector<int>(s.size(), -1));
        // vector<vector<int>> memo(s.size(), vector<int>(k, -1));
        // return recur(0, 0, s, k, memo, palin);
        
        
        //2. DP - 6 ms	8.4 MB
        return bottomUp(s, k);
    }
};