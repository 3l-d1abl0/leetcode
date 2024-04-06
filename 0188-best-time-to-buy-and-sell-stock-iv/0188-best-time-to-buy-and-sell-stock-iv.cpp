class Solution {
public:
    
    int recMemo(int idx, int buy, int tran, int K, vector<int> &prices, vector<vector<vector<int>>> &memo){
        
        if(idx== prices.size() || tran==K){
            return 0;
        }
        
        if( memo[idx][buy][tran] !=-1)
            return memo[idx][buy][tran];
        
        
        //skipping
        int skipping = recMemo(idx+1, buy, tran, K, prices, memo);
        
        int transaction;
        if(buy){
            transaction = -prices[idx]+ recMemo(idx+1, 0, tran, K, prices, memo);
        }else{
            transaction = prices[idx]+ recMemo(idx+1, 1, tran+1, K, prices, memo);
        }
        
        //cout<<idx<<" "<<buy<<" "<<tran<<" == "<<max(skipping, transaction)<<endl;
        return memo[idx][buy][tran] = max(skipping, transaction);
    }
    
    
     int bottomUp(vector<int> &prices, int K){
        
         int N = prices.size();
         
         /*
         [N][buy][K]    --> K transaction remaining
         
         */
         vector<vector<vector<int>>> dp(N+1, vector<vector<int>> (2, vector<int> (K+1, -1e7)));
         
         //Basecase- when idx == N 
         /*for(int buy=0; buy<=1; buy++){
             for(int k=0; k<=K; k++){
                 dp[N][buy][k] = 0;
             }
         }
         //base case - when transaction =K
         for(int idx=N-1; idx>=0; idx--){
             for(int buy=0; buy<=1; buy++){
                 dp[idx][buy][K] = 0;
             }
         }*/
         
         for(int idx=N; idx>=0; idx--){
             
             
             for(int k=K; k>=0; k--){
                 for(int buy=0; buy<=1; buy++){
                     
                     
                     if(idx==N){
                         dp[idx][buy][k] = 0;
                         continue;
                     }
                     if(k==K){
                         dp[idx][buy][k] = 0;
                         continue;
                     }
                     
                     int skipping = dp[idx+1][buy][k];
                     
                     int transaction;
                     //can buy
                     if(buy){
                         transaction = -prices[idx]+dp[idx+1][0][k];
                     }else{
                         transaction = prices[idx]+dp[idx+1][1][k+1];
                     }
                     
                     dp[idx][buy][k]= max(skipping, transaction);
                 }
             }
         }
         
         
         //can buy, and o transaction remaining
         return dp[0][1][0];
    }
    
    
    int topDown(vector<int> &stocks, int k){
        
        int N = stocks.size();
        
        vector<vector<vector<int>>> dp(N+1, vector<vector<int>> (k+1, vector<int> (2, 0)));
        
        //Base case N == 0 and K==0 all 0
        
        for(int idx = N-1; idx>=0; idx--){
            for(int K=1; K <=k; K++){
                for(int buy = 0; buy <=1; buy++){
                        
        
                dp[idx][K][buy] = dp[idx+1][K][buy]; //recur(idx+1, buy, K, stocks, N, memo);  //skip

                if(buy){
                    dp[idx][K][buy] = max(dp[idx][K][buy] , -stocks[idx] +dp[idx+1][K][0]);

                }else{
                    dp[idx][K][buy] = max(dp[idx][K][buy] , stocks[idx] +dp[idx+1][K-1][1]);
                }
                    
                    
                    
                }
            }
            
        }//for
        
        return dp[0][k][1];
        
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
    
    
    
    int maxProfit(int K, vector<int>& prices) {
        
        /*
        A transaction constitutes of buy ans sell,
        
        buy then sell - transaction 1
        
        buy then sell - transaction 2
        ...
        buy then sell - transaction K
        
        */
        
        int N = prices.size();
        //1.Recur+ Memoization
        //vector<vector<vector<int>>> memo(N, vector<vector<int>> (2, vector<int> (K, -1)));
        //return recMemo(0, true, 0, K, prices, memo);
        
        //2. bottomUp
        return bottomUp(prices, K);
        
        //Optimizign to 2D DP
        //return topDownSpaceOpti(prices, K);
        
        
        
        /*N*4
            0 1 2 3 4
            B S B S B
        */
        //vector<vector<int>> memo(N, vector<int> (2*K, -1));
        //return altRecur(0, 0, prices, K, memo);
        
        //return altDP(prices, K);
        
        return altDPOpti(prices, K);
        
        
    }
};