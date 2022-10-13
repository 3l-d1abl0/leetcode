class Solution {
public:
    bool method1(string s, vector<string> &wordDict){
        
      unordered_set < string > word_set(wordDict.begin(), wordDict.end());
      vector < bool > dp(s.length() + 1);
      dp[0] = true;

      for (int i = 1; i <= s.length(); i++) {
        for (int j = 0; j < i; j++) {
          if (dp[j] and word_set.find(s.substr(j, i - j)) != word_set.end()) {
            dp[i] = true;
            break;
          }
        }
      }
      
        return dp[s.length()];
        
    }
    
    bool method0(string s, vector<string> &wordDict){
        
      unordered_set < string > word_set(wordDict.begin(), wordDict.end());
      vector < bool > dp(s.length() + 1);
      dp[0] = true;

      for (int st = 0; st <= s.length(); st++) {
        for (int ed = st+1; ed <=s.length(); ed++) {
            
          //cout<<st<<" "<<ed<<" -> "<<s.substr(st, ed - st)<<endl;
          if (dp[st] and word_set.find(s.substr(st, ed - st)) != word_set.end()) {
            dp[ed] = true;
              //cout<<"FOUND\n";
              //st = ed-1;
            //break;
          }
        }
      }
      
        return dp[s.length()];
        
    }
    
    
    int method2(int idx, string s, vector<string> &wd, vector<int> &dp){
        
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
    
    bool wordBreak(string s, vector < string > & wordDict) {

        return method0(s, wordDict);
        return method1(s, wordDict);
        vector<int> dp(s.size()+1,-1);
        dp[s.size()] = 1;
        return method2(0, s, wordDict, dp);
    }
    
};