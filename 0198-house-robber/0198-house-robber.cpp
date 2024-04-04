class Solution {
public:
    
    int recMemo(int idx, vector<int> &nums, vector<int> &memo){
        
        if(idx<0)
            return 0;
        
        //IF we reach idx =0, it means we din not take idx=1, since have to maximize sum we include idx=0
        //if(idx==0) return nums[idx];
        
        if(memo[idx]!=-1)
            return memo[idx];
        
        
        //pick/Include
        int inSum = nums[idx]+recMemo(idx-2, nums, memo);
        
        //not pick //exclude
        int exSum = recMemo(idx-1, nums, memo);
        
        
        return memo[idx] = max(inSum, exSum);
        
    }
    
    int bottomUp(int N, vector<int> &nums){
        
        vector<int> dp(N, 0);
        /*
            dp[0] = nums[0]
            
            dp[1] = max(nums[0], nums[1]);
        */
        
        for(int i=0; i<N; i++){
            
            int inSum =0, exSum =0;
            
            //pick/Include
                inSum = nums[i]+ ( (i-2>=0)?dp[i-2]:0);
        
            //not pick //exclude
            
                exSum = (i-1>=0)?dp[i-1]:0;
            
            dp[i]=max(inSum, exSum);
            
        }
        
        
        return dp[N-1];
        
        
    }
    
    
    int opti(vector<int> &nums){
        
            int N = nums.size();
        
        
            int prev2 =0, prev1 = 0, curr =0;
            
            for(int i=0; i<N; i++){
            
                    //(include, exclude)
                 curr = max(nums[i]+prev2, prev1);
                
                //prepare previous for the next iteration
                prev2 = prev1;
                prev1 = curr;
            }
        
        return prev1;
        
    }
    
    int rob(vector<int>& nums) {
        
        
        //recur+memoization
        int N = nums.size();
        //vector<int> memo(N, -1);
        //return recMemo(N - 1, nums, memo);
        
        //return bottomUp(N, nums);
        
        
        //Space Optimization
        return opti(nums);
    }
};