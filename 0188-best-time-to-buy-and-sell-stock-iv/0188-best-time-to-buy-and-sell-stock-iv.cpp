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
    
    int maxProfit(int k, vector<int>& prices) {
        
        memset(memo, -1, sizeof(memo));
		return dp(0, true, k, prices);
        
    }
};