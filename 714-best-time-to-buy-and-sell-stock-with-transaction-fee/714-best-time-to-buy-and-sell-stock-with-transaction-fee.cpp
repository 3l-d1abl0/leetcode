class Solution {
public:
    int maxProfit(vector<int>& stocks, int fee) {
        
        int N = stocks.size();
        
        vector<vector<int>> dp(N+1, vector<int> (2,0));
        
        //dp[N] = 0;
        
        for(int i=N-1; i>=0; i--){
            
            
            for(int buy=1; buy>=0; buy--){
                
                
                int profit =0;
                
                if(buy){
                    
                    profit = max(-stocks[i]+ dp[i+1][0], 0+ dp[i+1][1]);
                    
                }else{
                    profit = max(stocks[i]+ dp[i+1][1]-fee, 0 + dp[i+1][0]);
                }
                
                
                dp[i][buy] = profit;
            }
            
        }
        
        //printDP(dp);
        return dp[0][1];
        
        
    }
};