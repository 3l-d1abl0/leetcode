class Solution {
public:
    
    int recur(int idx, int buy, vector<int> &prices, int N, vector<vector<int>> &memo){
        
        if(idx>=N)
            return 0;
        
        if(memo[idx][buy] !=-1)
            return memo[idx][buy];
        
        int profit = recur(idx+1, buy, prices, N, memo);
        
        if(buy==0){
            profit = max(profit, -prices[idx] +recur(idx+1, 1, prices, N, memo) );    
        }else{
            //addiong cool down
            profit = max(profit, prices[idx] +recur(idx+2, 0, prices, N, memo) );    
        }
        
        
        return memo[idx][buy] = profit;
    }
    
    int topDown(vector<int> &prices, int N){
        
        vector<vector<int>> dp(N+1, vector<int>(2, 0));
        
        //base case
        dp[N][0] = dp[N][1] = 0;
        
        
        for(int idx = N-1; idx>=0; idx--){
            
            for(int buy =0; buy<=1; buy++){
                
                
                dp[idx][buy] = dp[idx+1][buy];
        
                if(buy==0){
                    dp[idx][buy] = max(dp[idx][buy], -prices[idx] + dp[idx+1][1]);    
                }else{
                    //adding cool down
                    if(idx+2<=N-1)
                        dp[idx][buy] = max(dp[idx][buy], prices[idx] +dp[idx+2][0] ); 
                    else
                        dp[idx][buy] = max(dp[idx][buy], prices[idx] +0 ); 
                }
                
            }
            
        }//for
        
        
        return dp[0][0];
        
    }
    
    
        int topDownOpti(vector<int> &prices, int N){

            vector<vector<int>> dp(N+1, vector<int>(2, 0));
            
            vector<int> last(2, 0); //i+2
            vector<int> prev(2, 0); //i+1
            vector<int> curr(2, 0); //i

            //base case
            prev[0] = prev[1] = 0;


            for(int idx = N-1; idx>=0; idx--){

                for(int buy =0; buy<=1; buy++){


                    curr[buy] = prev[buy];

                    if(buy==0){
                        curr[buy] = max(curr[buy], -prices[idx] + prev[1]);    
                    }else{
                        //adding cool down
                        if(idx+2<=N-1)
                            curr[buy] = max(curr[buy], prices[idx] +last[0] ); 
                        else
                            curr[buy] = max(curr[buy], prices[idx] +0 ); 
                    }

                }
                
                
                last = prev;
                prev = curr;
                

            }//for


            return prev[0];

        }
    
    
    
    
    int maxProfit(vector<int>& prices) {
        
        int N= prices.size();
        
        ///1. Recursion + memoization
        //vector<vector<int>> memo(N, vector<int> (2, -1));
        //0 - can but ,1 - can't buy
        //return recur(0, 0, prices, N, memo);
        
        
        //2. TopDown DP
        //return topDown(prices, N);
        
        //3. TopDown - OPti
        return topDownOpti(prices, N);
    }
};