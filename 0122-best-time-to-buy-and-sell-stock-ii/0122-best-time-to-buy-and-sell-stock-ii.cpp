class Solution {
public:
    
    int recur(int idx, bool buy, vector<int> &prices, int N, vector<vector<int>> &memo){
        
        if(idx==N)
            return 0;
        
        if(memo[idx][buy]!=-1)
            return memo[idx][buy];
        
        //1. Skip
        int maxProfit = recur(idx+1, buy, prices, N, memo);
        
        //2. Buy
        if(buy){
            maxProfit = max(maxProfit, -prices[idx]+recur(idx+1, false, prices, N, memo) );
                        //also Zero Profit and Skip
        }else{  //3. sell
            maxProfit = max(maxProfit, prices[idx]+recur(idx+1, true, prices, N, memo) );
        }
        
        
        return memo[idx][buy] = maxProfit;
    }
    
    int topDown(vector<int> &prices, int N){
        
        vector<vector<int>> dp(N+1, vector<int> (2, 0));
        
        
        dp[N][0] = dp[N][1] =0;
        
        for(int idx = N-1; idx>=0; idx--){
            
            for(int buy =0; buy<=1; buy++){
                
                    dp[idx][buy] = dp[idx+1][buy];
                
                    if(buy){
                        dp[idx][buy] = max(dp[idx][buy], -prices[idx]+dp[idx+1][0] );
                    }else{  //3. sell
                        dp[idx][buy] = max(dp[idx][buy], prices[idx]+dp[idx+1][1] );
                    }
                
                
            }
            
        }//for
        
        
        return dp[0][1];
        
    }
    
    int maxProfit(vector<int>& prices) {
        
        
        int N = prices.size();
        
        //vector<vector<int>> memo(N, vector<int> (2, -1));
        
        //true - buy, false - sell
        //return recur(0, true, prices, N ,memo);
        
        return topDown(prices, N);
    }
};