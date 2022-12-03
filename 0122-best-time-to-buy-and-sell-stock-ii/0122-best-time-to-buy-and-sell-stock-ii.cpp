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
        }else{  //3. sell
            maxProfit = max(maxProfit, prices[idx]+recur(idx+1, true, prices, N, memo) );
        }
        
        
        return memo[idx][buy] = maxProfit;
    }
    
    int maxProfit(vector<int>& prices) {
        
        
        int N = prices.size();
        
        vector<vector<int>> memo(N, vector<int> (2, -1));
        
        //true - buy, false - sell
        return recur(0, true, prices, N ,memo);
    }
};