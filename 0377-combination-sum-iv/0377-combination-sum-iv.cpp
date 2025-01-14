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
        if(arr[i]<=target){ //Include and start from the beginning
            inc = rec(arr.size()-1, target-arr[i], arr, memo);
        }
        //exclude - go to next Index
        int exc = rec(i-1, target, arr, memo);
        
        return memo[i][target] = inc+exc;
    }
    
    int recursion(int target, vector<int> &nums, vector<int> &memo){

        if(target==0)
            return 1;

        if(memo[target]!=-1)
            return memo[target];

        int ans =0;
        for(int idx =0; idx<nums.size(); idx++){
            if(nums[idx]<=target)
                ans+=recursion(target-nums[idx], nums, memo);
        }
        
        return memo[target] = ans;
    }
    
    int dp(vector<int> &nums, int target){

            vector<int> memo (target+1, 0);

            memo[0]=1;

            for(int tar=1; tar<=target; tar++){


                long long int ans =0;
                for(int i=0; i<nums.size(); i++){

                    if(nums[i]<=tar)
                        ans += memo[tar-nums[i]];
                }

                memo[tar] = ans%INT_MAX;
            }


            return memo[target];
    }


    int bottomUp(int target, vector<int> &nums){
        
        vector<vector<long long int>> dp(nums.size()+1, vector<long long int> (target+1, 0));
        
        //can always make 0
        for(int i=0; i<=nums.size(); i++)
           dp[i][0] =1;
        
        
            for(int j=1; j<=target; j++){
                for(int i=1;i<=nums.size(); i++){
                    
                    if(nums[i-1]<=j)//Exclude+Include
                        dp[i][j] = ( (dp[i-1][j]%INT_MAX) + (dp[nums.size()][j-nums[i-1]]%INT_MAX) )%INT_MAX;
                    else{
                        dp[i][j] = dp[i-1][j];//Exclude
                    }
                
            }//i
        }//j
        
        
        return dp[nums.size()][target];
        
    }
    
    
    int bottomUp1D(int target, vector<int> &nums){
        
        vector<long long int> dp(target+1, 0);
        
         dp[0] =1;
                
         for(int j=1; j<=target; j++){
            for(int i=1;i<=nums.size(); i++){        

               if(nums[i-1]<=j)
                    dp[j] = ((dp[j]%INT_MAX)+ (dp[j-nums[i-1]]%INT_MAX)) %INT_MAX;

            }//i
        }//j
        
        return dp[target];
        
    }
    

    
    int combinationSum4(vector<int>& nums, int target) {
        
        //Method1 - Rec+ Memo
        //vector<vector<int>> memo(nums.size(), vector<int>(target+1, -1) );
        //return rec(nums.size()-1, target, nums, memo);
        
        //Method1.1 - Recursion
        //vector<int> memo(vector<int>(target+1, -1) );
        //return recursion(target, nums, memo);

        ////Method1.2 - DP
        return dp(nums, target);

        //Method2 - DP
        //return bottomUp(target, nums);

        //Method3 - 
        //return bottomUp1D(target, nums);
        
        
        
        
    }
};