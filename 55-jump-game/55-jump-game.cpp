class Solution {
public:
    
    int jump(vector<int> &nums, int idx, vector<int> &dp){
        
        if(idx>= nums.size()) return false;
        
        if(dp[idx]!=-1) return dp[idx];
        
        
        if(idx==nums.size()-1){
            dp[idx]=1;
            return dp[idx];
        }
        
        int steps = nums[idx];
        
        for(int i=1; i<=steps; i++){
            if(jump(nums, idx+i, dp)==1){
                dp[idx] =1;
                return true;
            }
        }
        
        dp[idx] = 0;
        return dp[idx];
    }
    
    bool canJump(vector<int>& nums) {
        
        vector<int> dp(nums.size(), -1);
        return jump(nums, 0, dp)==1;
    }
};