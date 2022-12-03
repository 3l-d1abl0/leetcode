class Solution {
public:
    int maxProfit(int k, vector<int>& stocks) {
        
                
        int N = stocks.size();
        
        vector<vector<vector<int>>> dp(N+1, vector<vector<int>> (2, vector<int> (k+1, 0)));
        //buy - 1 sell -0
        //dp[N][0][0] = 0;
        //  ...
        //dp[N][1][1] =0
        
        for(int i=N-1; i>=0; i--){
            
            
            for(int buy=1; buy>=0; buy--){
                
                for(int tx=1; tx<=k; tx++){
                    
                    int profit =0;

                    if(buy){

                        profit = max(-stocks[i]+ dp[i+1][0][tx], 0+ dp[i+1][1][tx]);

                    }else{
                        profit = max(stocks[i]+ dp[i+1][1][tx-1], 0 + dp[i+1][0][tx]);
                    }
                
                    dp[i][buy][tx] = profit;
                }
                
                
            }
            
        }
        
        //printDP(dp);
        
        return dp[0][1][k];
        
        
        
    }
};