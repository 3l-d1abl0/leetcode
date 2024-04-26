class Solution {
public:
    
    void dprint(vector<int> dp){
        
        for(int ele: dp){
            cout<<ele<<" ";
        }cout<<endl;
    }
    
    long long int minCoins(int N, int sum, vector<int> &arr){

        if(sum <0 || N<0)
            return INT_MAX;

        if(sum ==0)
            return 0;

        //exclude
        long long int exc = minCoins(N-1, sum, arr);

        //include once
        //int inc = minCoins(N-1, sum-arr[N], arr); covered in include again

        //incluide again
        long long int inc1 = minCoins(N, sum-arr[N], arr)+1;


        if(exc >= INT_MAX)
            return inc1;

        if(inc1 >= INT_MAX)
            return exc;

        return min(exc, inc1);


    }
    
    
    int rec(vector<int> &arr, int sum){
        
        long long int ans = minCoins(arr.size()-1, sum, arr);
        return ((ans>=INT_MAX)?-1:ans);
        
    }
    
    
    int topDown(int idx, int sum, vector<int> &arr, vector< vector<int>> &memo){

        
        // Base case: If we're at the first element
        if(idx == 0){
            // Check if the target sum is divisible by the first element
            if(sum % arr[0] == 0)
                return sum / arr[0]; // If yes, return the quotient as the answer
            else
                return 1e7; // Otherwise, return a very large value to indicate it's not possible
        }

        if(sum==0)
          return 0;


        if(memo[idx][sum] != -1)
            return memo[idx][sum];


        int notTaken = 0 + topDown(idx - 1, sum, arr, memo);

        int taken = 1e9; // Initialize 'taken' to a very large value
        if(arr[idx] <= sum)
            taken = 1 + topDown(idx, sum - arr[idx], arr, memo);

        // Store the minimum of 'notTaken' and 'taken' in the DP array and return it
        return memo[idx][sum] = min(notTaken, taken);



    }
    
    
    
    
    int memoization(vector<int> &arr, int sum){
        
        vector< vector<int>> memo(arr.size(), vector<int> (sum+1, -1));
        int ans = topDown(arr.size()-1, sum, arr, memo);
        
        return ((ans>=1e7)?-1:ans);
        
    }
    
    int bottomUp(int sum, vector<int> &arr){

        int N = arr.size();
    
        vector<vector<int>> dp(N, vector<int>(sum + 1, 0));

        
        for (int i = 0; i <= sum; i++) {
            if (i % arr[0] == 0)
                dp[0][i] = i / arr[0];
            else
                dp[0][i] = 1e9;
        }

        
        for (int idx = 1; idx < N; idx++) {
            for (int target = 0; target <= sum; target++) {
                
                int notTake = dp[idx - 1][target];

                
                int take = 1e9; // Initialize 'take' to a very large value
                if (arr[idx] <= target)
                    take = 1 + dp[idx][target - arr[idx]];

                // Store the minimum of 'notTake' and 'take' in the DP table
                dp[idx][target] = min(notTake, take);
            }
        }

        int ans = dp[N - 1][sum];

        if (ans >= 1e9)
            return -1;

        return ans;
        
    }
    
    
    
int bottomUpOpti(int sum, vector<int> &arr){

    int N = arr.size();
    vector<int> dp(sum+1, INT_MAX);

    for (int val = 0; val <= sum; val++) {
        if (val % arr[0] == 0)
            dp[val] = val / arr[0];
        else
            dp[val] = 1e9; // Set it to a very large value if not possible
    }

    for(int i=1; i<N; i++){
           for(int val=1; val<=sum; val++){

                if(arr[i] <= val)
                    dp[val] = min( dp[val], 1 + dp[val-arr[i]] );

        }

    }

    if (dp[sum] >= 1e9)
        return -1;
    
    return dp[sum];
}
    
    
    
    int coinChange(vector<int>& coins, int amount) {
        
        
        //recursion - TLE
        //return rec(coins, amount);
        
        //memoization 
        //return memoization(coins, amount);
        
        //bottomUp
        //return bottomUp(amount, coins);
        
        //bottomUpOpti
        return bottomUpOpti(amount, coins);
        
        
    }
    
    
};