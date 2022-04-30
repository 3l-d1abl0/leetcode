class Solution {
public:
    void printDP(vector<vector<int>> &stocks){

        for(auto row: stocks){
            for(int ele: row){
                cout<<ele<<" ";
            }
            cout<<endl;
        }
    }
        
    int maxProfit3(vector<int>& stocks) {
        
        
        int N = stocks.size();
        
        vector<vector<vector<int>>> dp(N+1, vector<vector<int>> (2, vector<int> (2, 0)));
        
        //dp[N][0][0] = 0;
        //  ...
        //dp[N][1][1] =0
        
        for(int i=N-1; i>=0; i--){
            
            
            for(int buy=1; buy>=0; buy--){
                
                for(int tx=0; tx<=1; tx++){
                    
                    int profit =0;

                    if(buy){

                        profit = max(-stocks[i]+ dp[i+1][0][1], 0+ dp[i+1][1][0]);

                    }else{
                        profit = max(stocks[i]+ dp[i+1][1][1], 0 + dp[i+1][0][0]);
                    }
                
                    dp[i][buy][tx] = profit;
                }
                
                
            }
            
        }
        
        //printDP(dp);
        
        return dp[0][1][1];
    }
    
    int maxProfit(vector<int>& stocks) {
        
        return maxProfit3(stocks);
        
        int N = stocks.size();
        
        vector<vector<int>> dp(N+1, vector<int> (2,0));
        
        //dp[N] = 0;
        
        for(int i=N-1; i>=0; i--){
            
            
            for(int buy=1; buy>=0; buy--){
                
                
                int profit =0;
                
                if(buy){
                    
                    profit = max(-stocks[i]+ dp[i+1][0], 0+ dp[i+1][1]);
                    
                }else{
                    profit = max(stocks[i]+ dp[i+1][1], 0 + dp[i+1][0]);
                }
                
                
                dp[i][buy] = profit;
            }
            
        }
        
        //printDP(dp);
        return dp[0][1];
    }
};