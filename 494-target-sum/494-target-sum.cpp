class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        
        //boils down to diff of subsets = target
        target = abs(target);
        int totalSum =0;
        for(int ele:nums){
            totalSum +=ele;
        }
        
        if(totalSum-target <0)
            return 0;
        
        if((totalSum-target) %2!=0)
            return 0;
        
        int newTotal = (totalSum-target)/2;
        
        return subSetSum(nums, newTotal);
        
    }
    
    int subSetSum(vector<int> &nums, int newTotal){
        
        
        vector<vector<int>> dp(nums.size()+1, vector<int>(newTotal+1, 0));
        
        for(int i=0; i<=newTotal; i++)
            dp[0][i] = 0;   //first row for empty lookup
        
        //for(int i=0; i<=nums.size(); i++)
            dp[0][0] = 1;   //1 way of makeing sum 0
        
        
        
        for(int i=1; i<=nums.size(); i++){
            
            for(int j=0; j<=newTotal; j++){ //starting from zero since we will check for sum =0 with elemetn 0
                
                dp[i][j]= dp[i-1][j];
                
                if(j>=nums[i-1])    //alsp covers if element is zero
                    dp[i][j] += dp[i-1][j-nums[i-1]] ;
            }
        }
        
        return dp[nums.size()][newTotal];
        
    }
};