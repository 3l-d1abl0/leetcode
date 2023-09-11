class Solution {
public:    
    
    int choose(int i, int availMask, int k, vector<vector<int>> &memo, vector<int> &sum) { 
        
        if (i == 1)
            return sum[availMask];
        
         //if (i == k) return (mask == ((1 << n) - 1)) ? 0 : 1e9;
        
        
        if(memo[i][availMask]!=-1)
            return memo[i][availMask];
        
        
        int ans = 1e9;
        
        for (int new_mask = availMask; new_mask > 0; new_mask = (new_mask - 1) & availMask) {
            
            int remainingMask = new_mask ^ availMask;
            int nextMaxSubsetSum = choose(i- 1, remainingMask, k, memo, sum);
            
            nextMaxSubsetSum = max(sum[new_mask], nextMaxSubsetSum);
            ans = min(ans, nextMaxSubsetSum);
        }
        
        return memo[i][availMask] = ans;
    }
    
    int bottomUp(vector<int> &cookies, vector<int> &sum, int K){
        
        int N = cookies.size();
        int sz = 1<<N;
        
        vector<vector<int>> dp(K+1, vector<int> (1<<N, INT_MAX));
        
        //Base: for k==1, sum is the sum of elements of mask
        for(int mask=1; mask<sz; mask++)
            dp[1][mask] = sum[mask];
        
        for(int k=2; k<=K; k++){
            
            for(int availMask = 0; availMask <sz; availMask++ ){
            
                for (int new_mask = availMask; new_mask > 0; new_mask = (new_mask - 1) & availMask) {

                    int remainingMask = new_mask ^ availMask;
                    int nextMaxSubsetSum = dp[k-1][remainingMask];

                    nextMaxSubsetSum = max(sum[new_mask], nextMaxSubsetSum);
                    dp[k][availMask] = min(dp[k][availMask], nextMaxSubsetSum);
                }
        
            }
        }
        
        
        return dp[K][sz-1];
    }
    
    int distributeCookies(vector<int>& cookies, int k) {
        
        
        int N = cookies.size();
        
        //Calculate sum of every mask;
        vector<int> sum (1 << N, 0); 
        
        for (int i = 0; i < (1 << N); i++) {
            for (int j = 0; j < N; j++) {
                if (i & (1 << j)) {
                    sum[i] += cookies[j];
                }
            }
        }
        
        vector<vector<int>> memo(k+1, vector<int> (1<<N, -1));
        //return choose(k, (1 << N) - 1, k, memo, sum); //all 1s, every bag is available
        
        return bottomUp(cookies, sum, k);
    }
};