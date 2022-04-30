class Solution {
public:
    int maxProfit(vector<int>& stocks) {


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
};