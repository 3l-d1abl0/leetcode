class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        
        int profit = 0, buy = 0, sell = 0, days = prices.size();
        
        while(buy < days && sell < days)
        {
            while(buy < days - 1 && prices[buy + 1] < prices[buy])
                buy++; // find the valley of prices               
            
            sell = buy+1;
            
            while(sell < days - 1 && prices[sell + 1] > prices[sell])
                sell++; // find the peak of prices
            
            if(sell<days)//i.e if bot buy ans sell are valid index. ifnore if only Buy
                profit += prices[sell] - prices[buy];
                
            buy = sell + 1;
        }
        
        return profit;
    }
        
    
};