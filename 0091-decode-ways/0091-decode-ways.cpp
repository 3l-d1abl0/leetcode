class Solution {
public:
    
    int decode(int idx, string &s, int &N, vector<int> &dp){
        
        if(idx==N) return 1;
        
        if(s[idx]=='0') return dp[idx] = 0;
        
        if(dp[idx]!=-1) return dp[idx];
        
        
        int ans =0;
        int val =0;
        for(int i=idx; i<N; i++){
            val = val*10+(s[i]-'0');
            if(val>=1 && val <=26){
                //cout<<val<<endl;
                ans += decode(i+1, s, N, dp);
            }else{
                break;
            }
        }
        
        
        
        return dp[idx] = ans;
        
    }
    
    int memoization(string &s){
        
        int N = s.size();
        int idx =0;
        
        vector<int> memo(N, -1);
        
        return decode(idx, s, N, memo);
        
    }
    
    
    int dynamicP(string &s){
        
        
        int N = s.size();
        if(N==0) return 0;
        if(s[0] == '0') return 0;
            
        vector<int> dp(N+1, 0);
        
        //base
        dp[0] =1;
        
        dp[1] = (s[0] -'0')!=0?1:0;
        
        for(int i=2; i<=N; i++){
            
            int one = s[i-1] -'0';
            
            if(one>=1 && one<=9)
                dp[i] +=dp[i-1];
            
            int two = (s[i-2]-'0')*10 + one;
            
            if(two >=10 && two <=26)
                dp[i] +=dp[i-2];
            
        }
        
        
        return dp[N];
        
    }
    
    int numDecodings(string s) {
        
        return memoization(s);
        
        
        //return dynamicP(s);
        
    }
};