class Solution {
public:
    
    int decode(int idx, string &s, int &N, vector<int> &dp){
        
        if(idx==N) return 1;
        
        if(s[idx]=='0') return dp[idx] = 0;
        
        if(dp[idx]!=-1) return dp[idx];
        
        
        int ans =0, val =0;
        ans += decode(idx+1,s, N, dp);  //single Digit

        if(idx+1 <N){
            if(s[idx]=='1' ||  (s[idx]=='2' && s[idx+1]<='6'))
             ans += decode(idx+2, s, N, dp);
        }

        /*for(int i=idx; i<N; i++){
            val = val*10+(s[i]-'0');
            if(val>=1 && val <=26){
                //cout<<val<<endl;
                ans += decode(i+1, s, N, dp);
            }else{
                break;
            }
        }*/
        
        
        
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
        //cant start with Zero
        if(s[0] == '0') return 0;
            
        vector<int> dp(N+1, 0);
        //base
        dp[N] =1;
        
        //dp[1] = (s[0] -'0')!=0?1:0;
        
        for(int i=N-1; i>=0; i--){
            
            if(s[i]!='0'){
                dp[i] +=dp[i+1];//single Digit

                //Two digits
                if(i+1<=N-1){
                    if (s[i]=='1' || (s[i]=='2' && s[i+1]<='6'))
                        dp[i] +=dp[i+2];
                    cout<<"I: "<<i<<endl;
                }
            }

            // int one = s[i-1] -'0';
            
            // if(one>=1 && one<=9)
                
            
            // int two = (s[i-2]-'0')*10 + one;
            
            // if(two >=10 && two <=26)
            //     dp[i] +=dp[i-2];
            
        }
        
        
        return dp[0];
        
    }
    
    int numDecodings(string s) {
        
        //1. Method1 - Top Down recursion + memoization from 0 to N
        //TC - O(2^N) SC -O(N)
        //return memoization(s);
        
        //2. DP - bottom Up 0 - N
        //TC - O(N) SC - O(N)
        return dynamicP(s);
        
    }
};