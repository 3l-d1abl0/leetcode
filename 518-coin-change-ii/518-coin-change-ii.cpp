class Solution {
public:
    
    int coinsWays(int N, int sum, vector<int> &arr){

        if(sum <0 || N<0)
            return 0;

        if(sum ==0)
            return 1;

        //exclude
        int exc = coinsWays(N-1, sum, arr);

        //include once
        //int inc = coinsWays(N-1, sum-arr[N], arr); covered in include again

        //incluide again
        int inc1 = coinsWays(N, sum-arr[N], arr);

        return exc+inc1;


    }
    
    
    int topDown(int N, int sum, vector<int> &arr, vector< vector<int>> &memo){

        if(sum <0 || N<0)
            return 0;

        if(memo[N][sum]!= -1 )
            return memo[N][sum];

        if(sum ==0)
            return memo[N][sum]=1;


        //exclude
        int exc = topDown(N-1, sum, arr, memo);

        //include once
        //int inc = topDown(N-1, sum-arr[N], arr, memo); covered in include again

        //incluide again
        int inc1 = topDown(N, sum-arr[N], arr, memo);

        return memo[N][sum] = exc+inc1;


    }
    
    
    int bottomUp(int sum, vector<int> &arr){

        int N = arr.size();
        vector< vector<int> > dp(N+1, vector<int> (sum+1));

        //i==0 =>0ways
        for(int j=0; j<=sum; j++)
            dp[0][j] = 0;

        for(int i=0; i<=N; i++)
            dp[i][0] = 1;


        for(int i=1; i<=N; i++){

            for(int j=1; j<=sum; j++){

                if(j<arr[i-1])//exclude
                    dp[i][j] = dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j] + dp[i][j-arr[i-1]];

            }

        }


        return dp[N][sum];
    }
    
    
    int bottomUpOpti(int sum, vector<int> &arr){

        int N = arr.size();
        vector<int> dp(sum+1, 0);

        for(int i=0; i<=N; i++)
            dp[0] = 1;


        for(int i=0; i<N; i++){
               for(int j=arr[i]; j<=sum; j++){

                    dp[j] = dp[j] + dp[j-arr[i]];

            }

        }

        return dp[sum];
    }
    
    
    
    
    int change(int amount, vector<int>& coins) {
        
        //Number of Ways
        
        //recursion
        //return coinsWays(coins.size()-1, amount, coins);
        
        //memoization - AC
        // vector< vector<int>> memo(coins.size(), vector<int> (amount+1, -1));
        // return topDown(coins.size()-1, amount, coins, memo);
    
        //dp - SD
        //return bottomUp(amount, coins);
        
        //dp - 2D
        return bottomUpOpti(amount, coins);
        
    }
};