class Solution {
public:
    
    
    	int memo[1001][2][101];
	int dp(int i, int buy, int k, vector<int>& prices) {
		if (i == prices.size()) return 0;
		if (memo[i][buy][k] != -1) return memo[i][buy][k];
		// dont buy/sell
		
        if (k == 0) return 0;
        
        int ans = dp(i + 1, buy, k, prices);
		
		// buy
		if (buy) {
			ans = max(ans, -prices[i] + dp(i + 1, false, k, prices));
		}
		else {
			ans = max(ans, prices[i] + dp(i + 1, true, k - 1, prices));
		}

		return memo[i][buy][k] = ans;
	}
    
    
    int topDown(vector<int> &stocks, int k){
        
        int N = stocks.size();
        
        vector<vector<vector<int>>> dp(N+1, vector<vector<int>> (k+1, vector<int> (2, 0)));
        
        //Base case N == 0 and K==0 all 0
        
        for(int idx = N-1; idx>=0; idx--){
            for(int K=1; K <=k; K++){
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
        
        return dp[0][k][1];
        
    }
    
    int topDownSpaceOpti(vector<int> &stocks, int k){
        
        int N = stocks.size();
        
        vector<vector<int>> prev (k+1, vector<int> (2, 0));
        vector<vector<int>> curr (k+1, vector<int> (2, 0));
        
        //Base case N == 0 and K==0 all 0
        
        for(int idx = N-1; idx>=0; idx--){
            for(int K=1; K <=k; K++){
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
        
        return curr[k][1];
        
        
    }
    
    
        int altRecur(int idx, int txNo, vector<int> &stocks, int K, vector<vector<int>> &memo){

            if(idx == stocks.size() || txNo == 2*K)
                return 0;

            if(memo[idx][txNo]!=-1)
                return memo[idx][txNo];

            int profit = altRecur(idx+1, txNo, stocks, K, memo);

            if(txNo%2==0){ // Buy

                profit = max(profit, -stocks[idx] + altRecur(idx+1, txNo+1, stocks, K, memo) );
            }else{
                profit = max(profit, stocks[idx] + altRecur(idx+1, txNo+1, stocks, K, memo) );
            }

            return memo[idx][txNo] = profit;
        }
    
        int altDP(vector<int> &stocks, int K){

            int N = stocks.size();
            vector<vector<int>> dp(N+1, vector<int> ( (2*K)+1, 0));

            for(int idx =N-1; idx >=0; idx--){

                for(int txNo=2*K-1 ; txNo >=0; txNo--){

                        dp[idx][txNo] = dp[idx+1][txNo];

                        if(txNo%2==0){ // Buy

                            dp[idx][txNo] = max(dp[idx][txNo], -stocks[idx] + dp[idx+1][txNo+1] );
                        }else{
                            dp[idx][txNo] = max(dp[idx][txNo], stocks[idx] + dp[idx+1][txNo+1] );
                        }


                }
            }//for

            return dp[0][0];
        }
    
        int altDPOpti(vector<int> &stocks, int K){
        
            int N = stocks.size();

            vector<int> prev( (2*K)+1, 0);
            vector<int> curr( (2*K)+1, 0);
            
            for(int idx =N-1; idx >=0; idx--){

                for(int txNo=2*K-1 ; txNo >=0; txNo--){

                        curr[txNo] = prev[txNo];

                        if(txNo%2==0){ // Buy

                            curr[txNo] = max(curr[txNo], -stocks[idx] + prev[txNo+1] );
                        }else{
                            curr[txNo] = max(curr[txNo], stocks[idx] + prev[txNo+1] );
                        }


                }
                
                prev = curr;
            }//for

            return prev[0];
        }
    
    
    
    int maxProfit(int K, vector<int>& prices) {
        
        int N = prices.size();
        
        //1.Recur +memo
        //memset(memo, -1, sizeof(memo));
		//return dp(0, true, K, prices);
        
        //2. TopDown DP
        //return topDown(prices, K);
        
        //Optimizign to 2D DP
        //return topDownSpaceOpti(prices, K);
        
        
        
        /*N*4
            0 1 2 3 4
            B S B S B
        */
        vector<vector<int>> memo(N, vector<int> (2*K, -1));
        return altRecur(0, 0, prices, K, memo);
        
        //return altDP(prices, K);
        
        //return altDPOpti(prices, K);
        
        
    }
};