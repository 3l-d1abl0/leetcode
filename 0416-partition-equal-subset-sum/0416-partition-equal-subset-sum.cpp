class Solution {
public:
    
    bool rec(int N, int sum , vector<int> &arr){

        if(sum==0)
            return true;

        if(N<0 || sum <0)
            return false;

        bool exclude = rec(N-1, sum , arr);
        bool include = rec(N-1, sum-arr[N], arr);


        return exclude | include;

    }

    //top-down approach
    bool topDown(int N, int sum , vector<int> &arr, vector<vector<int>> &memo){

        if(sum==0)
            return true;

        if(N<0 || sum <0)
            return false;

        if(memo[N][sum]!=-1) return memo[N][sum];

        bool exclude = rec(N-1, sum , arr);
        bool include = rec(N-1, sum-arr[N], arr);


        return memo[N][sum] = (exclude | include);

    }
    
    
    bool bottomUp(int sum, vector<int> &prices){

                //N+1 x sum+1

        int N = prices.size();
        vector<vector<bool>> dp(N+1, vector<bool> (sum+1, 0));


        for(int i=0; i<=N; i++)
            dp[i][0] = true;    //can always make zero

        for(int i=1; i<=N; i++){

            for(int j=1; j<=sum; j++){

                bool exclude = dp[i-1][j];

                bool include = false;
                if(prices[i-1] <= j) 
                   include = dp[i-1][j-prices[i-1]];

                dp[i][j] = (exclude | include); 

            }
        }

        return dp[N][sum];
    }
    
    
    bool bottomUpSpaceOpti(int sum, vector<int> &prices){

        int N = prices.size();

        vector<bool> dp (sum+1, false);
        dp[0] =true;
        for(int i=0; i<N; i++){

            //for(int j=prices[i]; j<=sum; j++){
            for(int j=sum; j>=prices[i]; j--){

                dp[j] = dp[j] || dp[j-prices[i]];
            }
        }

        return dp[sum];
    }
    
    
    bool canPartition(vector<int>& nums) {
        
        int sum =0;
        for(int ele: nums) sum+=ele;
        
        if(sum & 1) //odd cant be halved
            return false;
        
        //return subset(0, nums, sum/2);
        
        //recursion - TLE
        //return rec(nums.size()-1, sum/2, nums);
        
        //topDown - TLE
        //vector<vector<int>> memo (nums.size(), vector<int> ((sum/2)+1, -1));
        //return topDown(nums.size()-1, sum/2, nums, memo);
        
        //Bottom UP - AC
        //return bottomUp(sum/2, nums);
        
        //Bottom up Space Optimizartion - AC
        return bottomUpSpaceOpti(sum/2, nums);
    }
};