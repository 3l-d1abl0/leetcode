impl Solution {
    
    
    fn way1(prices: Vec<i32>) -> i32{
        
        let (mut profit, mut buy) = (0, prices[0]);

        for i in 1..prices.len() {
            profit = i32::max(profit, prices[i] - buy);
            buy = i32::min(buy, prices[i]);
        }

        return profit;
        
    }
    
    pub fn max_profit(prices: Vec<i32>) -> i32 {
        
        return Solution::way1(prices);
        
    }
}