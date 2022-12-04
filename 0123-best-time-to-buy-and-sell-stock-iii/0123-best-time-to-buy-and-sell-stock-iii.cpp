class Solution {
public:
        int maxProfit3(vector<int>& stocks) {
        
        
        int N = stocks.size();
        
        vector<vector<vector<int>>> dp(N+1, vector<vector<int>> (2, vector<int> (3, 0)));
        //buy - 1 sell -0
        //dp[N][0][0] = 0;
        //  ...
        //dp[N][1][1] =0
        
        for(int i=N-1; i>=0; i--){
            
            
            for(int buy=1; buy>=0; buy--){
                
                for(int tx=1; tx<=2; tx++){
                    
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
        
        return dp[0][1][2];
    }
    
    int method1(vector<int> &stocks){
        
        int N = stocks.size();
	    vector<vector<int>> dp(3, vector<int> (N,0));


        for(int i=1; i<=2; i++){

            int prev_profit = INT_MIN;
            //cant make any transaction at j=0
            for(int j=1; j<N; j++){

                //1. not making any transaction on jth day
                dp[i][j] = dp[i][j-1];

                prev_profit = max(prev_profit, dp[i-1][j-1] - stocks[j-1] ); 
                
                dp[i][j] =max(dp[i][j], prev_profit+stocks[j]);
            }
        }
        
        
        return dp[2][N-1];
        
    }
    
    int recur(int idx, bool buy, int K, vector<int> &stocks, int N, vector<vector<vector<int>>> &memo ){
        
        if(idx == N || K==0)
            return 0;
        
        if(memo[idx][K][buy] !=-1)
            return memo[idx][K][buy];
        
        int profit = recur(idx+1, buy, K, stocks, N, memo);  //skip
        
        if(buy){
            profit = max(profit, -stocks[idx] +recur(idx+1, 0, K, stocks, N, memo));
            
        }else{
            profit = max(profit, stocks[idx] +recur(idx+1, 1, K-1, stocks, N, memo));
        }
        
        return memo[idx][K][buy] = profit;
    }
    
    int topDown(vector<int> &stocks, int K){
        
        int N = stocks.size();
        
        vector<vector<vector<int>>> dp(N+1, vector<vector<int>> (K+1, vector<int> (2, 0)));
        
        //Base case N == 0 and K==0 all 0
        
        for(int idx = N-1; idx>=0; idx--){
            for(int K=1; K <=2; K++){
                for(int buy = 0; buy <=1; buy++){
                        
        
                dp[idx][K][buy] = dp[idx+1][K][buy]; //recur(idx+1, buy, K, stocks, N, memo);  //skip

                if(buy){
                    dp[idx][K][buy] = max(dp[idx][K][buy] , -stocks[idx] +dp[idx+1][K][0]);

                }else{
                    dp[idx][K][buy] = max(dp[idx][K][buy] , stocks[idx] +dp[idx+1][K-1][1]);
                }
                    
                    
                    
                }
            }
            
        }//for
        
        return dp[0][K][1];
        
    }
    
    int topDownSpaceOpti(vector<int> &stocks, int K){
        
        int N = stocks.size();
        
        vector<vector<int>> prev (K+1, vector<int> (2, 0));
        vector<vector<int>> curr (K+1, vector<int> (2, 0));
        
        //Base case N == 0 and K==0 all 0
        
        for(int idx = N-1; idx>=0; idx--){
            for(int K=1; K <=2; K++){
                for(int buy = 0; buy <=1; buy++){
                        
        
                curr[K][buy] = prev[K][buy]; //recur(idx+1, buy, K, stocks, N, memo);  //skip

                if(buy){
                    curr[K][buy] = max(curr[K][buy] , -stocks[idx] +prev[K][0]);

                }else{
                    curr[K][buy] = max(curr[K][buy] , stocks[idx] +prev[K-1][1]);
                }
                    
                    
                    
                }
            }
            
            prev = curr;
            
        }//for
        
        return curr[K][1];
        
        
    }
    
    int maxProfit(vector<int>& stocks) {

        //return method1(stocks);
        //return maxProfit3(stocks);
        
        
        //Recursion
        int K=2;    //true- can buy false - can't buy
        int N = stocks.size();
        
        //vector<vector<vector<int>>> memo (N, vector<vector<int>> (K+1, vector<int> (2, -1)));
	    //return recur(0, 1, K, stocks, N, memo);
        
        //Converting recursion to Top Down
        return topDown(stocks, K);
        
        //Optimizign to 2D DP
        return topDownSpaceOpti(stocks, K);
    }
};