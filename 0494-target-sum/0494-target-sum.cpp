class Solution {
public:
    int f(int idx, vector<int> &nums, int target, int sum, vector<vector<int>> &dp){
        
        if(idx == nums.size()){
            
            if(sum == target)
                return 1;
            
            return 0;
        }
        
        if(dp[idx][sum+1000]!= -1) return dp[idx][sum+1000];
        
        //make negative
        int neg = f(idx+1, nums, target, sum-nums[idx], dp);
        
        int pos = f(idx+1, nums, target, sum+nums[idx], dp);
        
        
        return dp[idx][sum+1000] = pos+neg;
        
    }
    
    int memoization(vector<int>& nums, int target){
        
        int idx =0;
        int sum = 0;
        
        //Range -1000 to 1000
        //Memoization
        vector<vector<int>> memo(nums.size(), vector<int>(2002, -1));
        return f(idx, nums, target, sum, memo);
    }
    
    int bottomUp(vector<int> &nums, int target){

                int sum = 0;
        sum = accumulate(nums.begin(), nums.end(), sum);
        
        /*
            x + y = sum
            x - y = target
            
            
            x = sum+target /2
            y = sum - target    /2
            
            min (x, y)
        */
        
        
        if(target > sum) return 0;
        
        if( ((sum+target)&1) || ((sum-target)&1) )
            return 0;
        
        int targetSum = (sum-target)/2;
        
            int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(targetSum + 1, 0));

        if (nums[0] == 0)
            dp[0][0] = 2;  // 2 cases - pick and not pick
        else
            dp[0][0] = 1;  // 1 case - not pick

        if (nums[0] != 0 && nums[0] <= targetSum)
            dp[0][nums[0]] = 1;  // 1 case - pick

        for (int ind = 1; ind < n; ind++) {
            for (int target = 0; target <= targetSum; target++) {

                int notTaken = dp[ind - 1][target];

                int taken = 0;
                if (nums[ind] <= target)
                    taken = dp[ind - 1][target - nums[ind]];

                dp[ind][target] = (notTaken + taken);
            }
        }
        return dp[n - 1][targetSum];
    }
    
    int bottomUpOpti(vector<int> &nums, int target){
        
        int sum = 0;
        sum = accumulate(nums.begin(), nums.end(), sum);
        
        /*
            x + y = sum
            x - y = target
            
            
            x = sum+target /2
            y = sum - target    /2
            
            min (x, y)
        */
        
        
        if(target > sum) return 0;
        
        if( ((sum+target)&1) || ((sum-target)&1) )
            return 0;
        
        int targetSum = (sum-target)/2;
        
        vector<int> dp(targetSum+1, 0);
        
        //base - can always make zero sum
        dp[0]=1;
        
        for(int i=0; i<nums.size(); i++){
            
            for(int j=targetSum; j>=nums[i]; j--){
                
                dp[j] = (dp[j] + dp[j-nums[i]]);
            }
        }
        
        return dp[targetSum];
        
    }
    
    
    int findTargetSumWays(vector<int>& nums, int target) {
        
        //1. Include exclude to get the target
        //return memoization(nums, target);
        
        //bottom up DP
        return bottomUp(nums, target);
        
        //return bottomUpOpti(nums, target);
    }
};