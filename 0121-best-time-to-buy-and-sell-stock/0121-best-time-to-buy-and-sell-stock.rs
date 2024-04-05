use std::cmp;

impl Solution {
    
    
    fn way1(prices: Vec<i32>) -> i32{
        
        let (mut profit, mut buy) = (0, prices[0]);

        for i in 1..prices.len() {
            profit = i32::max(profit, prices[i] - buy);
            buy = i32::min(buy, prices[i]);
        }

        return profit;
        
    }
    
    fn way2(prices: Vec<i32>) -> i32 {
        
        let (mut max_sell, mut min_buy) = (prices[0], prices[0]);
        let mut profit = 0;
        prices.iter().for_each(|&x| {
            if x < min_buy {
                min_buy = x;
                max_sell = x;
            } else if x > max_sell {
                let new_profit = x - min_buy;
                if new_profit > profit {
                    max_sell = x;
                    profit = new_profit;
                }
            }
        });
        profit
    }
    
    
    fn way3(prices: Vec<i32>) -> i32 {
        prices.into_iter()
            .fold((std::i32::MAX, 0), |(low, profit), price|
                (
                    cmp::min(low, price),
                    cmp::max(profit, price - low)
                )
            )
            .1
    }
    
    fn way4(prices: Vec<i32>) -> i32 {
        
        prices.iter().fold((0, None), |(mut ret, mut lowest), p| {
            
            let lowest = lowest.map_or(Some(p), |l| {
                ret = ret.max(p - l);
                Some(if p > l {l}else{p})
            });
                
            (ret, lowest)
        }).0
    }
    
    pub fn max_profit(prices: Vec<i32>) -> i32 {
        
        //return Solution::way1(prices);
        
        //return Solution::way2(prices);
        
        
        //return Solution::way3(prices);
        
        return Solution::way4(prices);
        
    }
}