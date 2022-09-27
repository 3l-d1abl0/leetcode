class Solution {
public:
    
    long long int MOD = 9223372036854775807;
    
    int rec(int i, int target, vector<int> &arr, vector<vector<int>> &memo){
        
        if(target==0)
            return 1;
        
        if(i== -1)
                return 0;
        
        if(memo[i][target]!=-1)
            return memo[i][target];
        
        int inc = 0;
        if(arr[i]<=target){
            inc = rec(arr.size()-1, target-arr[i], arr, memo);
        }
        
        int exc = rec(i-1, target, arr, memo);
        
        return memo[i][target] = inc+exc;
    }
    
    int bottomUp(int target, vector<int> &nums){
        
        vector<vector<long long int>> dp(target+1, vector<long long int> (nums.size()+1, 0));
        
	if (nums.size() == 0) return 0;
	
    for (int i = 0; i <= nums.size(); i++)
		dp[0][i] = 1;
        
	for (int i = 1; i <= target; i++) {
		for (int j = 1; j <= nums.size(); j++) { // using each coin
			dp[i][j] = dp[i][j - 1];
			if (i >= nums[j - 1])
				dp[i][j] = ((dp[i][j]%INT_MAX) + (dp[i - nums[j - 1]][nums.size()]%INT_MAX))%INT_MAX;
		}
	}
        
        
        return dp[target][nums.size()];
        
    }
    

    
    int combinationSum4(vector<int>& nums, int target) {
        
        return bottomUp(target, nums);
        
        vector<vector<int>> memo(nums.size(), vector<int>(target+1, -1) );
        
        return rec(nums.size()-1, target, nums, memo);
        
        
        
    }
};