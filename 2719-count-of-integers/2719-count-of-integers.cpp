class Solution {
public:
    
    int MOD = 1e9+7;
    int memo[23][2][200];
        
    void subtract(string &num){
        
        int N = num.size();
        
        for(int i=N-1; i>=0; i--){
                
            if(num[i]=='0')
                num[i]='9';
            else{
                num[i]--;
                break;
            }
        }
    }
    
    int solve(string num, int idx, bool last, int dig_sum, int max_sum, int min_sum){
        
        if(idx==num.size()){
         
            if(dig_sum<=max_sum && dig_sum>=min_sum){
                return 1;
            }else{
                return 0;
            }
        }
        
        
        if(memo[idx][last][dig_sum]!=-1)
            return memo[idx][last][dig_sum];
        
        long long int ans =0;
        int limit = last ? num[idx]-'0':9;
        for(int di=0; di<=limit; di++){
            
            
            ans =( ans + solve(num, idx+1, (last && di==limit), dig_sum+di, max_sum, min_sum) )%MOD;
            
        }
        
        return memo[idx][last][dig_sum] = ans;
    }
    
    int count(string num1, string num2, int min_sum, int max_sum) {
        
        subtract(num1);
        //cout<<num2<<" "<<num1<<endl;
        memset(memo, -1, sizeof(memo));
        int ans2 = solve(num2, 0, true, 0, max_sum, min_sum);
        
        memset(memo, -1, sizeof(memo));
        int ans1 = solve(num1, 0, true, 0, max_sum, min_sum);
        
        //cout<<ans2<<" - "<<ans1<<endl;
        return (ans2-ans1+MOD)%MOD;
    }
};