class Solution {
public:
    
    int recur(int idx, bool buy, vector<int> &prices, vector<vector<int>> &memo){
        
        int N = prices.size();
        
        if(idx==N)
            return 0;
        
        if(memo[idx][buy]!=-1)
            return memo[idx][buy];
        
        //1. Skip - do nothing
        int skipping = recur(idx+1, buy, prices, memo);
        
        //2. can Buy
        int transaction = INT_MIN;
        if(buy){
            transaction =  recur(idx+1, false, prices, memo) - prices[idx];
                        //also Zero Profit and Skip
        }else{  //3. sell
            transaction = recur(idx+1, true, prices, memo) + prices[idx];
        }
        
        
        return memo[idx][buy] = max(skipping, transaction);
        
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
        
        vector<vector<int>> memo(N, vector<int> (2, -1));
        
        //true - can buy, false - can sell
        return recur(0, true, prices, memo);
        
        //return bottomUp(prices, N);
    }
};