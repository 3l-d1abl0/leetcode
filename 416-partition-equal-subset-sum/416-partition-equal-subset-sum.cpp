class Solution {
public:
    
    bool subset(int idx, vector<int> &nums, int sum){
        
        vector<vector<int>> dp(nums.size()+1, vector<int>(sum+1,0));
        
        for(int i=0; i<nums.size(); i++)
            dp[i][0]= true;
        
        
        for(int i=1; i<=nums.size(); i++){
            
            
            for(int j=1; j<=sum; j++){
                    
                if(nums[i-1] <= j )
                    dp[i][j] = dp[i-1][j-nums[i-1]];
                
                dp[i][j] |= dp[i-1][j];
            }
        }
        
        return dp[nums.size()][sum];
    }
    
    bool canPartition(vector<int>& nums) {
        
        int sum =0;
        for(int ele: nums){
            sum += ele;
        }
        
        if(sum & 1)
            return false;
        
        return subset(0, nums, sum/2);
    }
};