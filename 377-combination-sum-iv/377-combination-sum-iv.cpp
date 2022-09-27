class Solution {
public:
    
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
        
        vector<vector<int>> dp(nums.size()+1, vector<int> (target+1, 0));
        
        for(int i=0; i<=nums.size(); i++)
           dp[i][0] =1;
        
        //for(int i=1; i<=target; i++)
            //dp[0][i] =1;
        
        
            
            for(int j=1; j<=target; j++){
                
                for(int i=nums.size()-1;i>=0; i--){
                    
                if(nums[i]<=j)
                    dp[i][j] = ((i-1)>=0?dp[i-1][j]:dp[0][j]) + dp[0][j-nums[i]];
                else{
                    dp[i][j] = ((i-1)>=0?dp[i-1][j]:dp[0][j]);
                }
                
            }
        }//for
        
        
        for(auto row: dp){
            for(int ele: row)
                cout<<ele<<" ";
            
            cout<<endl;
        }
        
        
        return dp[nums.size()][target];
        
    }
    

    
    int combinationSum4(vector<int>& nums, int target) {
        
        //return bottomUp(target, nums);
        
        vector<vector<int>> memo(nums.size(), vector<int>(target+1, -1) );
        
        return rec(nums.size()-1, target, nums, memo);
        
        
        
    }
};