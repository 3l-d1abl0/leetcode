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
        
        /*vector<int> dp(nums.size(), 1e4+10);    //max possible jump - linear
        return f(nums, 0, dp);*/
        
        return f1(nums);
        
    }
    
    int f1(vector<int> nums){
        
        int N = nums.size();
        
        vector<int> dp(N, 1e4+10);
        
        dp[N-1] = 0;    //0 steps to reach n-1 from n-1
        
        for(int i= N-2; i>=0; i--){     //from n-2 to 0
            
            
            for(int j=1; j<= nums[i]; j++){
                
                
                dp[i] = min(dp[i], 1+ dp[min(N-1, i+j)]);
                
            }
        }
        
        
        return dp[0];
    }
    
};