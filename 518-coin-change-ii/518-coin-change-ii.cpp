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
    
    
    
    int change(int amount, vector<int>& coins) {
        
        //recursion
        //return coinsWays(coins.size()-1, amount, coins);
        
        //memoization
        vector< vector<int>> memo(coins.size(), vector<int> (amount+1, -1));
        return topDown(coins.size()-1, amount, coins, memo);
    
    }
};