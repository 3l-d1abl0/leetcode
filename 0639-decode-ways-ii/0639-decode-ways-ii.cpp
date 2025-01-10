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

        long long int ans =0;
        int val=0;

        int ways = 1;

        if(s[idx]=='*')
            ways = 9;

        ans = ( 1ll * (ways%MOD) * (recur(idx+1, s, memo)%MOD) )%MOD;   //when considering just 1 char (*)
        ways =0;
        //consider Two Character
        if(idx+1 < N){

            if(s[idx] == '*'){

                if(s[idx+1] == '*')
                    ways = 15;
                else{
                    if(s[idx+1]<='6')
                        ways = 2;
                    else
                        ways =1;
                }

            }else if (s[idx] < '3'){

                //1_
                //2_

                if(s[idx+1] =='*'){ //second char is *

                    if(s[idx]=='1')
                        ways = 9;  //11 .. 19
                    else
                        ways = 6;   //21 ..26

                }else{
                    //both place are digit - just check if between 1-26

                    if(stoi(s.substr(idx, 2)) <= 26)
                        ways = 1;
                }

            }

            if(ways !=0){

                

                ans+= 1ll*ways*recur(idx+2, s, memo);;
            }
        }
        
        //cout<<"IDX: "<<idx<<" "<<ans<<endl;
        return memo[idx] = ans%MOD;
    }
    int method1(string &s){

        vector<int> memo((int)s.size(), -1);
        return recur(0, s, memo);
    }

    int method2(string &s){

            int N = s.size();
            vector<int> dp(N+1, -1);

            dp[N]=1;

            long long int ans = 0;
            for(int idx=N-1; idx>=0; idx--){

                        if(s[idx]=='0'){
                            dp[idx] =0;
                            continue;
                        }

                        int ways = 1;

                        if(s[idx]=='*')
                            ways = 9;

                        ans = ( 1ll * (ways%MOD) * (dp[idx+1]%MOD) )%MOD;   //when considering just 1 char (*)
                        ways =0;
                        //consider Two Character
                        if(idx+1 < N){

                            if(s[idx] == '*'){

                                if(s[idx+1] == '*')
                                    ways = 15;
                                else{
                                    if(s[idx+1]<='6')
                                        ways = 2;
                                    else
                                        ways =1;
                                }

                            }else if (s[idx] < '3'){

                                //1_
                                //2_

                                if(s[idx+1] =='*'){ //second char is *

                                    if(s[idx]=='1')
                                        ways = 9;  //11 .. 19
                                    else
                                        ways = 6;   //21 ..26

                                }else{
                                    //both place are digit - just check if between 1-26

                                    if(stoi(s.substr(idx, 2)) <= 26)
                                        ways = 1;
                                }

                            }

                            if(ways !=0){

                                

                                ans+= 1ll*ways*dp[idx+2];
                            }
                        }//if idx+1<N

                        dp[idx] = ans%MOD;

            }//for idx


            return dp[0];
    }

    int method3(string &s){
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

        //2. Method - Dynamic Programming - bottom Up
        return method2(s);

        //2. Method3 - Dynamic Programming
        //return method3(s);
    }
};