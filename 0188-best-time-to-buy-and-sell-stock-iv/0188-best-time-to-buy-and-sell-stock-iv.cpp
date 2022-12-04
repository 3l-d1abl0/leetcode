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
    
    
    
    int maxProfit(int K, vector<int>& prices) {
        
        
        //1.Recur +memo
        //memset(memo, -1, sizeof(memo));
		//return dp(0, true, K, prices);
        
        //2. TopDown DP
        //return topDown(prices, K);
        
        //Optimizign to 2D DP
        return topDownSpaceOpti(prices, K);
        
    }
};