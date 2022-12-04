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
    
    int maxProfit(vector<int>& prices) {
        
        int N= prices.size();
        
        vector<vector<int>> memo(N, vector<int> (2, -1));
        
        //0 - can but ,1 - can't buy
        return recur(0, 0, prices, N, memo);
    }
};