class Solution {
public:
    
    int memo[10][2][10];
    int solve(string num, int idx, bool last, int sum){
        
        if(idx==num.size()){
            
            //cout<<str<<" = "<<sum<<endl;
            return sum;
        }
        
        if(memo[idx][last][sum]!=-1)
            return memo[idx][last][sum];
            
        
        int ans = 0;
        int limit = last? num[idx]-'0': 9;
        for(int i=0; i<=limit; i++){
            
            if(i==1)
                ans+=solve(num, idx+1, last && i==limit, sum+1);
            else
                ans+=solve(num, idx+1, last && i==limit, sum+0);
            
        }
        
        
        return memo[idx][last][sum] = ans;
        
    }
    
    int countDigitOne(int n) {
        
        string num = to_string(n);
        
        memset(memo, -1, sizeof(memo));
        cout<<num<<endl;
        return solve(num, 0, true, 0);
    }
};