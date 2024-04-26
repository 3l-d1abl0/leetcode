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
        vector< vector<int> > dp(N+1, vector<int> (sum+1));

        //i==0 =>INT_MX
        for(int j=0; j<=sum; j++)
            dp[0][j] = INT_MAX;

        //Sum 0 cab be made with 0 coin
        for(int i=0; i<=N; i++)
            dp[i][0] = 0;


        for(int i=1; i<=N; i++){

            for(int j=1; j<=sum; j++){

                if(j<arr[i-1])//exclude
                    dp[i][j] = dp[i-1][j];
                else
                    dp[i][j] = min({INT_MAX*1LL, dp[i-1][j]*1LL, 1LL + dp[i][j-arr[i-1]] });

            }

        }

        return dp[N][sum];
    }
    
    
    
int bottomUpOpti(int sum, vector<int> &arr){

    int N = arr.size();
    vector<int> dp(sum+1, INT_MAX);

    for(int i=0; i<=N; i++)
        dp[0] = 0;


    for(int i=0; i<N; i++){
           for(int j=1; j<=sum; j++){

                if(j>= arr[i])
                dp[j] = min({INT_MAX*1LL, dp[j]*1LL, 1LL + dp[j-arr[i]] });

        }

    }

    return dp[sum];
}
    
    
    
    int coinChange(vector<int>& coins, int amount) {
        
        
        //recursion - TLE
        //return rec(coins, amount);
        
        //memoization 
        return memoization(coins, amount);
        
        //bottomUp
        //int ans = bottomUp(amount, coins);
        //return ((ans>=INT_MAX || ans<0)?-1:ans);
        
        //bottomUpOpti
        int ans = bottomUpOpti(amount, coins);
        return ((ans>=INT_MAX || ans<0)?-1:ans);
        
    }
    
    
};