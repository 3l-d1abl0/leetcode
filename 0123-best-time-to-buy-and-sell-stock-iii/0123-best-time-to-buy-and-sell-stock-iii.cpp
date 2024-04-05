class Solution {
public:
        int maxProfit3(vector<int>& stocks) {
        
        
        int N = stocks.size();
        
        vector<vector<vector<int>>> dp(N+1, vector<vector<int>> (2, vector<int> (3, 0)));
        //buy - 1 sell -0
        //dp[N][0][0] = 0;
        //  ...
        //dp[N][1][1] =0
        
        for(int i=N-1; i>=0; i--){
            
            
            for(int buy=1; buy>=0; buy--){
                
                for(int tx=1; tx<=2; tx++){
                    
                    int profit =0;

                    if(buy){

                        profit = max(-stocks[i]+ dp[i+1][0][tx], 0+ dp[i+1][1][tx]);

                    }else{
                        profit = max(stocks[i]+ dp[i+1][1][tx-1], 0 + dp[i+1][0][tx]);
                    }
                
                    dp[i][buy][tx] = profit;
                }
                
                
            }
            
        }
        
        //printDP(dp);
        
        return dp[0][1][2];
    }
    
    int method1(vector<int> &stocks){
        
        int N = stocks.size();
	    vector<vector<int>> dp(3, vector<int> (N,0));


        for(int i=1; i<=2; i++){

            int prev_profit = INT_MIN;
            //cant make any transaction at j=0
            for(int j=1; j<N; j++){

                //1. not making any transaction on jth day
                dp[i][j] = dp[i][j-1];

                prev_profit = max(prev_profit, dp[i-1][j-1] - stocks[j-1] ); 
                
                dp[i][j] =max(dp[i][j], prev_profit+stocks[j]);
            }
        }
        
        
        return dp[2][N-1];
        
    }
    
    int recMemo(int idx, bool buy, int K, vector<int> &stocks, vector<vector<vector<int>>> &memo){
        
        int N = stocks.size();
        
        //index over OR transactions over
        if(idx == N || K==2)
            return 0;
        
        if(memo[idx][buy][K] !=-1)
            return memo[idx][buy][K];
        
        int profit_when_skipped = recMemo(idx+1, buy, K, stocks, memo);  //skip
        
        int transaction;
        //can buy 
        if(buy){
            transaction = -stocks[idx] +recMemo(idx+1, 0, K, stocks, memo);
        //can sell
        }else{
            transaction = stocks[idx] +recMemo(idx+1, 1, K+1, stocks, memo);
        }
        
        return memo[idx][buy][K] = max(profit_when_skipped, transaction);
    }
    
    int bottomUp(vector<int> &stocks, int K){
        
        int N = stocks.size();
        
        vector<vector<vector<int>>> dp(N+1, vector<vector<int>> (2, vector<int> (K+1, -1e7)));
        
        //Base case idx == N - for every buy and k
        for(int k=0;  k<=K; k++){
            for(int buy = 0; buy <=1; buy++){
                dp[N][buy][k] = 0;
            }
        }
        
        //K==2 for all idx and buy
        for(int idx=0;  idx<=N; idx++){
            for(int buy = 0; buy <=1; buy++){
                dp[idx][buy][K] = 0;
            }
        }
        
        
        for(int idx = N-1; idx>=0; idx--){
            for(int k=K-1; k >=0; k--){
                for(int buy = 0; buy <=1; buy++){
                        
                    //skipping
                    int skipping = dp[idx+1][buy][k];

                    int transaction;
                    //can buy
                    if(buy){
                        transaction = -stocks[idx] + dp[idx+1][0][k];

                    }else{
                        transaction = stocks[idx] + dp[idx+1][1][k+1];
                    }
                    
                    
                    dp[idx][buy][k] = max (skipping, transaction);
                    
                }//buy
            }//k
            
        }//for
        
        //cout<<dp[0][0][0]<<" "<<dp[0][0][1]<<" "<<dp[0][0][2]<<endl;
        //cout<<dp[0][1][0]<<" "<<dp[0][1][1]<<" "<<dp[0][1][2]<<endl;
        //cout<<"-------------------"<<endl;
        
        //oth stock, can buy, 0 transaction
        return dp[0][1][0];
        
    }
    
    int topDownSpaceOpti(vector<int> &stocks, int k){
        
        int N = stocks.size();
        
        vector<vector<int>> prev (k+1, vector<int> (2, 0));
        vector<vector<int>> curr (k+1, vector<int> (2, 0));
        
        //Base case N == 0 and K==0 all 0
        
        for(int idx = N-1; idx>=0; idx--){
            for(int K=1; K <=k; K++){
                for(int buy = 0; buy <=1; buy++){
                        
        
                curr[K][buy] = prev[K][buy]; //recur(idx+1, buy, K, stocks, N, memo);  //skip

                if(buy){
                    curr[K][buy] = max(curr[K][buy] , -stocks[idx] +prev[K][0]);

                }else{
                    curr[K][buy] = max(curr[K][buy] , stocks[idx] +prev[K-1][1]);
                }
                    
                    
                    
                }
            }
            
            prev = curr;
            
        }//for
        
        return curr[k][1];
        
        
    }
    
    int altRecur(int idx, int txNo, vector<int> &stocks, int K, vector<vector<int>> &memo){
        
        if(idx == stocks.size() || txNo == 2*K)
            return 0;
        
        if(memo[idx][txNo]!=-1)
            return memo[idx][txNo];
        
        int profit = altRecur(idx+1, txNo, stocks, K, memo);
        
        if(txNo%2==0){ // Buy
            
            profit = max(profit, -stocks[idx] + altRecur(idx+1, txNo+1, stocks, K, memo) );
        }else{
            profit = max(profit, stocks[idx] + altRecur(idx+1, txNo+1, stocks, K, memo) );
        }
        
        return memo[idx][txNo] = profit;
    }
    
    int altDP(vector<int> &stocks, int K){
        
        int N = stocks.size();
        vector<vector<int>> dp(N+1, vector<int> ( (2*K)+1, 0));
        
        for(int idx =N-1; idx >=0; idx--){
            
            for(int txNo=2*K-1 ; txNo >=0; txNo--){
         
                    dp[idx][txNo] = dp[idx+1][txNo];
        
                    if(txNo%2==0){ // Buy 0

                        dp[idx][txNo] = max(dp[idx][txNo], -stocks[idx] + dp[idx+1][txNo+1] );
                    }else{ //1
                        dp[idx][txNo] = max(dp[idx][txNo], stocks[idx] + dp[idx+1][txNo+1] );
                    }
                
                
            }
        }//for
        
        return dp[0][0];
    }
    
    int altDPOpti(vector<int> &stocks, int K){
        
            int N = stocks.size();

            vector<int> prev( (2*K)+1, 0);
            vector<int> curr( (2*K)+1, 0);
            
            for(int idx =N-1; idx >=0; idx--){

                for(int txNo=2*K-1 ; txNo >=0; txNo--){

                        curr[txNo] = prev[txNo];

                        if(txNo%2==0){ // Buy

                            curr[txNo] = max(curr[txNo], -stocks[idx] + prev[txNo+1] );
                        }else{
                            curr[txNo] = max(curr[txNo], stocks[idx] + prev[txNo+1] );
                        }


                }
                
                prev = curr;
            }//for

            return prev[0];
        }
    
    
    
    int maxProfit(vector<int>& stocks) {

        //return method1(stocks);
        //return maxProfit3(stocks);
        
        
        //Recursion
        int K=2;    //true- can buy false - can't buy
        int N = stocks.size();
        
        //1. Recursion + Memoization
        vector<vector<vector<int>>> memo (N, vector<vector<int>> (2, vector<int> (K+1, -1)));
        //true - can buy, false - can sell
	    //return recMemo(0, 1, 0, stocks, memo);
        /*
            N: 0--> N
          buy: --> 1 -> 0 -> 1
            k:  --> 0 -> 1 -> 2
        */
        
        
        
        //2. Converting recursion to Top Down
        return bottomUp(stocks, K);
        
        //3. Optimizign to 2D DP
        //return topDownSpaceOpti(stocks, K);
        
        
        /*N*4
            0 1 2 3 4
            B S B S B
        */
        
        //1.Recursion - Buy -sell as individual Transaction, hence 2*K
        //vector<vector<int>> memo(N, vector<int> (2*K, -1));
        //return altRecur(0, 0, stocks, K, memo);
        
        //2. DP - Top Down
        //return altDP(stocks, K);
        
        //3. DP - Optimized
        return altDPOpti(stocks, K);
    }
};