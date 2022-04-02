class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        vector<vector<int>> dp(coins.size()+1, vector<int>(amount+1, -1));
        
        int minCoins =   solve(coins.size(), coins, amount, dp);
        
        if(minCoins == INT_MAX-1)
            return -1;
        else
            return minCoins;
        
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