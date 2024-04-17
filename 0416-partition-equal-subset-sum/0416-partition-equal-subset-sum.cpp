class Solution {
public:
    

    //top-down approach - recursion
    bool topDown(int idx, int sum, vector<int> &arr, vector<vector<int>> &memo) {

        if(sum ==0)
            return true;

        if(idx==0)
            return sum == arr[0];

        if(memo[idx][sum]!=-1)
            return memo[idx][sum];

        bool exclude = topDown(idx-1, sum, arr, memo);

        bool include = false;
        if(arr[idx]<=sum)
            include = topDown(idx-1, sum-arr[idx], arr, memo);


        return memo[idx][sum] = exclude | include;
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
        
        //recursion - TLE
        //return rec(nums.size()-1, sum/2, nums);
        
        //cout<<sum<<" "<<sum/2<<" N="<<nums.size()<<endl;
        
        //topDown - Recursion+Memo- TLE
        vector<vector<int>> memo (nums.size(), vector<int> ((sum/2)+1, -1));
        return topDown(nums.size()-1, sum/2, nums, memo);
        
        //Bottom UP - AC
        //return bottomUp(sum/2, nums);
        
        //Bottom up Space Optimizartion - AC
        return bottomUpSpaceOpti(sum/2, nums);
    }
};