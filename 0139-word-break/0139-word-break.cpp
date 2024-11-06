class Solution {
public:

        
    bool method0(int idx, string &s, set <string> &word_set, vector<int> &memo){
          /*
            Start from index 0, and get substring till n-1,
            check if any substring exit, recur for the next Part
            
            f(0)
            
            0-0 + f(1)  , 0-1 +f(2), 0-2+f(3)     ...........  0-(n-1)+f(n)
          
          */
          if (idx >= s.length())
            return true;
          
            //cout<<"idx: "<<idx<<endl;
            if (memo[idx]!=-1)
                return memo[idx];
        
          for (int end = idx + 1; end <= s.length(); end++) {
            if (word_set.find(s.substr(idx, end - idx)) != word_set.end() and method0(end, s, word_set, memo)) {
              return memo[idx] = true;
            }
          }
          return memo[idx] = false;
    }
    
    
    bool method1(string s, vector<string> &wordDict){
    
      //Create a set of the words
      unordered_set < string > word_set(wordDict.begin(), wordDict.end());
      vector < bool > dp(s.length() + 1, false);
        
      //base  
      dp[s.length()] = true;
      
      //j is the boundary
      for (int i = s.length()-1; i >=0 ; i--) {
        for (int j = i+1; j <= s.length(); j++) {
            if(word_set.find(s.substr(i, j-i)) != word_set.end() and dp[j]) {
                dp[i] = true;
                break;
            }
        }//j
      }//i
      
        return dp[0];
        
    }
    
    int method2(int idx, string s, vector<string> &wd, vector<int> &dp){
        
        /*
            Total Time Complexity:
                The number of unique recursive states is O(n) due to memoization.
                For each state, there are O(m) iterations, and each comparison can take O(n).
                Therefore, the total time complexity is:
                    O(n×m×n)=O(n^2×m)
        */
        
        if(idx==s.size())
            return 1;
        //cout<<"idx = "<<idx<<endl;
        if(dp[idx]!=-1)
            return dp[idx];
        
        for(int i=0; i<wd.size(); i++){
            
            int len = wd[i].size();
            
            if(wd[i].compare(s.substr(idx, len))==0){
                
                if(method2(idx+len, s, wd, dp)){
                    dp[idx] = 1;
                    return dp[idx];
                }
            }
               
        }//for
        
        dp[idx]=0;
        return dp[idx];
    }
    
    int method3(string s, vector<string> &wd){
        
        
        int N = s.size();
        
        vector<int> dp(N+1, false);
        
        dp[N] = true;
        
        for(int idx=N-1; idx>=0; idx--){
            
            for(int i=0; i<wd.size(); i++){
                
                int len = wd[i].size();
                
                if(idx+len-1 >=N)
                    continue;
                
                if(wd[i].compare(s.substr(idx, len))==0){
                
                    if(dp[idx+len]==true){
                        dp[idx] = true;
                        break; //no need to check more wd[i]    
                    }
                }
                
            }//for i
        }//for idx
        
        return dp[0];
    }

    
    bool wordBreak(string s, vector < string > & wordDict) {
        
        //Method0 - Set + Recursion+Memoization -19ms - O(n^2)
        // vector<int> memo(s.size(), -1);
        // set < string > word_set(wordDict.begin(), wordDict.end());
        // return method0(0, s, word_set, memo);
        
        //Method1 - dp - 15ms  - O(n^2)
        //return method1(s, wordDict);
        
        // vector<int> dp(s.size()+1,-1);
        // dp[s.size()] = 1;
        // return method2(0, s, wordDict, dp);     //8ms - memoization
        
        
        return method3(s, wordDict);
    }
    
};