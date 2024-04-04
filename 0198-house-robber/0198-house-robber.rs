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
    
    pub fn rob(nums: Vec<i32>) -> i32 {
        
        let n = nums.len();
        let mut memo = vec![-1; n];
        Solution::rec_memo(n - 1, &nums, &mut memo)        
    }

}