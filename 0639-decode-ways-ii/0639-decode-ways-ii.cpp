class Solution {

private:
    int MOD = 1e9+7;

    int recur(int idx, string &s, vector<int> &memo){

        int N = (int)s.size();
        if(idx==N)
            return 1;

        if(memo[idx]!=-1)
            return memo[idx];
        
        if(s[idx]=='0')
            return 0;

        int ans =0;
        int val=0;
        

        if(s[idx]=='*'){
            for(int wild=1; wild<=9; wild++){
                int newVal = val*10+wild;
                ans+=recur(idx+1, s, memo);
                ans%=MOD;

                if(idx+1<N){

                    if(s[idx+1]=='*'){

                        for(int wild=1; wild<=9; wild++){
                            int newVal2 = newVal*10+wild;
                            if(newVal2>=1 && newVal2 <=26){
                                ans+=recur(idx+2, s, memo);
                                ans%=MOD;
                            }
                        }

                    }else{

                        int newVal2 = newVal*10+(s[idx+1]-'0');
                        if(newVal2>=1 && newVal2 <=26){
                            ans+=recur(idx+2, s, memo);
                            ans%=MOD;
                        }

                    }
                }//if N

            }//for
        }else{

            int newVal = val*10+(s[idx]-'0');
            ans+=recur(idx+1, s, memo);
                
            if(idx+1<N){

                if(s[idx+1]=='*'){

                    for(int wild=1; wild<=9; wild++){
                        int newVal2 = newVal*10+wild;
                        if(newVal2>=1 && newVal2 <=26){
                            ans+=recur(idx+2, s, memo);
                            ans%=MOD;
                        }
                    }

                }else{

                    int newVal2 = newVal*10+(s[idx+1]-'0');
                    if(newVal2>=1 && newVal2 <=26){
                        ans+=recur(idx+2, s, memo);
                        ans%=MOD;
                    }

                }
            }//if N


        }//else *
        
        return memo[idx] = ans%MOD;
    }
    int method1(string &s){

        vector<int> memo((int)s.size(), -1);
        return recur(0, s, memo);
    }

    int method2(string &s){
        const int M = 1e9 + 7;
        int n = s.size();
        vector<long long> dp(n + 1, -1); // Memoization array initialized to -1

        // Helper function for recursion with memoization
        function<long long(int)> decode = [&](int i) {
            if (i < 0) return 1LL; // Base case
            if (dp[i] != -1) return dp[i];

            long long ans = 0;

            if (s[i] == '*') {
                ans = 9 * decode(i - 1) % M; // '*' can be any digit 1-9
                if (i > 0) {
                    if (s[i - 1] == '1') ans = (ans + 9 * decode(i - 2)) % M;
                    else if (s[i - 1] == '2') ans = (ans + 6 * decode(i - 2)) % M;
                    else if (s[i - 1] == '*') ans = (ans + 15 * decode(i - 2)) % M;
                }
            } else {
                ans = s[i] != '0' ? decode(i - 1) : 0; // Current digit alone
                if (i > 0) {
                    string twoDigits = s.substr(i - 1, 2);
                    if (s[i - 1] == '*' && s[i] <= '6') {
                        ans = (ans + 2 * decode(i - 2)) % M; // '*' + '1-6'
                    } else if (s[i - 1] == '*') {
                        ans = (ans + decode(i - 2)) % M; // '*' + '7-9'
                    } else if (s[i - 1] != '*' && "10" <= twoDigits && twoDigits <= "26") {
                        ans = (ans + decode(i - 2)) % M;
                    }
                }
            }

            return dp[i] = ans;
        };

        return decode(n - 1) % M;
    }

public:
    int numDecodings(string s) {
        

        //1. Method1 - Recursion - top Down
        //return method1(s);


        //2. Method2 - Dynamic Programming
        return method2(s);
    }
};