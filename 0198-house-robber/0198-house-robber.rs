impl Solution {

        fn rec_memo(idx: usize, nums: &[i32], memo: &mut Vec<i32>) -> i32 {
        if idx == 0 {
            return nums[idx];
        }
        
        if idx == 1 {
            return nums[0].max(nums[1]);
        }

        if memo[idx] != -1 {
            return memo[idx];
        }

        // pick/include
        let in_sum = nums[idx] + Solution::rec_memo(idx - 2, nums, memo);

        // not pick/exclude
        let ex_sum = Solution::rec_memo(idx - 1, nums, memo);

        memo[idx] = in_sum.max(ex_sum);
        memo[idx]
    }
    
    fn bottom_up(n: usize, nums: &[i32]) -> i32 {
        let mut dp = vec![0; n];

        for i in 0..n {
            let in_sum = nums[i] + if i >= 2 { dp[i - 2] } else { 0 };
            let ex_sum = if i >= 1 { dp[i - 1] } else { 0 };

            dp[i] = in_sum.max(ex_sum);
        }

        dp[n - 1]
    }
    
    pub fn rob(nums: Vec<i32>) -> i32 {
        
        let n = nums.len();
        let mut memo = vec![-1; n];
        //Solution::rec_memo(n - 1, &nums, &mut memo)        
        
        Solution::bottom_up(n, &nums)
    }

}