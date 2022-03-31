class Solution {
public:
    int rob(vector<int>& nums) {
     
            int N = nums.size();
        
            vector<int> dp(N, 0);
        
        
            dp[0]= nums[0];
            for(int i=1; i<N; i++){
                    
                int include = nums[i];
                    
                if(i>1)
                    include +=dp[i-2];
                
                int exclude = dp[i-1];
                
                dp[i]= max(include, exclude);
            }
        
        return dp[N-1];
    }
};