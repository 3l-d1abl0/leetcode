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
public:
    int numDecodings(string s) {
        

        //1. Method1
        return method1(s);
    }
};