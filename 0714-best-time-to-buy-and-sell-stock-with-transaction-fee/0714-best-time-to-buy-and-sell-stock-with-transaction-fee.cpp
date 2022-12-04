class Solution {
public:
    int maxProfit2(vector<int>& prices, int fee) {
        
        
        int profit = 0, buy = 0, sell = 0, days = prices.size();
        
        while(buy < days && sell < days)
        {
            while(buy < days - 1 && prices[buy + 1] < prices[buy])
                buy++; // find the valley of prices               
            
            sell = buy;
            
            while(sell < days - 1 && prices[sell + 1] > prices[sell])
                sell++; // find the peak of prices
            
            if(sell==buy)
                profit += prices[sell] - prices[buy];
            else
                profit += prices[sell] - prices[buy]-fee;
                
            buy = sell + 1;
        }
        
        return profit;
    }
    
    
    int recur(int idx, int buy, int fee, vector<int> &stocks, int N, vector<vector<int>> &memo){
        
        if(idx==N)
            return 0;
        
        if(memo[idx][buy] !=-1)
            return memo[idx][buy];
        
        int profit = recur(idx+1, buy, fee, stocks, N, memo);
        
        if(buy==0){
            profit = max(profit, -stocks[idx]+recur(idx+1, 1, fee, stocks, N, memo) );
        }else{
            profit = max(profit, stocks[idx]-fee+ recur(idx+1, 0, fee, stocks, N, memo) );
        }
     
        
        return memo[idx][buy] = profit;
    }
    
    int maxProfit(vector<int>& stocks, int fee) {
        
        int N = stocks.size();
        
        //Crest Trough
        //return maxProfit2(stocks, fee);
        
        vector<vector<int>> memo(N, vector<int>(2, -1));
        return recur(0, 0, fee, stocks, N, memo);
        
        
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