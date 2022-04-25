class Solution {
public:
    int f(vector<int> &nums, int idx, vector<int> &dp){
        
        if(idx>=nums.size()-1)  return 0;
        
        if(dp[idx]!=1e4+10) return dp[idx];
        
        for(int i=1; i<=nums[idx]; i++){
            dp[idx] = min(dp[idx], f(nums, idx+i, dp)+1);
        }
        
        return dp[idx];
    }
    
    int jump(vector<int>& nums) {
        
        vector<int> dp(nums.size(), 1e4+10);    //max possible jump - linear
        return f(nums, 0, dp);
        
    }
};