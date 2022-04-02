class Solution {
public:
    
    void dprint(vector<int> dp){
        
        for(int ele: dp){
            cout<<ele<<" ";
        }cout<<endl;
    }
    
    int coinChange(vector<int>& coins, int amount) {
        
        vector<int> dp(amount+1, 1e8);

        
        
        dp[0]=0;
        for(int row=0; row<coins.size(); row++){
            
            for(int j=1; j<=amount; j++){
                
                
                if(j >= coins[row])
                    dp[j] = min(dp[j], 1+dp[j-coins[row]]);
            }
        //    dprint(dp);
        }
        
        
        return (dp[amount]==1e8?-1: dp[amount]);
        
    }
    
    int solve(int idx, vector<int> &coins, int amount, vector<vector<int>> &dp){
            
        
        if(idx==0 && amount !=0){
            return INT_MAX-1;    
        }
        
        if(amount==0){
            return 0;
        }
        
        if(dp[idx][amount]!=-1)
            return dp[idx][amount];
        
        //include
        if(amount>=coins[idx-1])
            return  (dp[idx][amount] = min(solve(idx-1, coins, amount, dp), 1+solve(idx, coins, amount-coins[idx-1], dp)));
        
        return (dp[idx][amount] = solve(idx-1, coins, amount, dp));
        
    
    }
};