class Solution {
public:
    
    const int MOD = 1e9+7;
    
    void subtract(string &str){
        
        int N = str.size();
        
        for(int i=N-1; i>=0; i--){
            
            if(str[i]=='0')
                str[i]='9';
            else{
                str[i]--;
                break;
            }
        }
    }
    
    //idx, last, prevD, stepStatus, started
    int memo[101][2][10][2];
    int solve(string str, string curr, int idx, bool last, int prevD, bool noTrailingZero){
        
        if(idx==str.size()){
         //   cout<<"cur= "<<curr<<": "<<stepStatus<<endl;
            return noTrailingZero==true;
        }
        
        
        if(memo[idx][last][prevD][noTrailingZero]!=-1)
            return memo[idx][last][prevD][noTrailingZero];
        
        int ans =0;
        int limit = last ? str[idx]-'0':9;
        
        for(int di=0; di<=limit; di++){
            
            
            
            bool noTrailingZeroNow = noTrailingZero || di>0;
            bool newLast = (last&& di==limit);
            
            if(noTrailingZero==false){//0
                
                ans = (ans + solve(str, curr+to_string(di), idx+1, newLast, di, noTrailingZeroNow) )%MOD;
                
            }else{//parent digit in not zero
                
                if(abs(prevD-di)==1){
                    ans = (ans + solve(str, curr+to_string(di), idx+1, newLast, di, noTrailingZeroNow) )%MOD;
                }
            }
            
            
            
        }
        
        
        return memo[idx][last][prevD][noTrailingZero] = ans;
    }
    
    int countSteppingNumbers(string low, string high) {
        
        
        memset(memo, -1, sizeof(memo));
        
        //string, index, last, previous_digit, sum, started
        int hAns = solve(high, "", 0, true, 0, false);
        
       // cout<<"================"<<endl;
        subtract(low);
        memset(memo, -1, sizeof(memo));
        int lAns = solve(low, "", 0, true, 0, false);
        
        return (hAns-lAns+MOD)%MOD;
        
    }
};