class Solution {
public:
    
    int decode(int idx, string &s, int &N, vector<int> &dp){
        
        if(idx==N) return 1;
        
        if(s[idx]=='0') return 0;
        
        if(dp[idx]!=-1) return dp[idx];
        int val = s[idx] -'0';
        
        int ans =0;
        if(val>=1 && val <=26){
            //cout<<val<<endl;
            ans += decode(idx+1, s, N, dp);
        }
        
        if(idx+1<N){
            
            val = val*10+(s[idx+1]-'0');
            if(val>=1 && val <=26){
                //cout<<val<<endl;
                ans += decode(idx+2, s, N, dp);
            }
        }
        
        
        return dp[idx] = ans;
        
    }
    
    int numDecodings(string s) {
        
        int N = s.size();
        int idx =0;
        
        vector<int> dp(N, -1);
        
        return decode(idx, s, N, dp);
        
    }
};