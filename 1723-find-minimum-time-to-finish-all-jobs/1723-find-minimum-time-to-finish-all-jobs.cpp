class Solution {
public:
    
    int dfs(int idx, int availMask, vector<vector<int>> &memo, vector<int> &jobs, vector<int> &sum, int K){
        
        if(idx==1)
            return sum[availMask];
        
        if(memo[idx][availMask]!=-1)
            return memo[idx][availMask];
        
        
        int ans = 1e9;
        
        //generate subset of the availmask
        for(int new_mask= availMask; new_mask>0; new_mask = (new_mask-1)&availMask){
            
            int remainingMask = new_mask^availMask;
            int nextBucketMaxSubsetSum = dfs(idx-1, remainingMask, memo, jobs, sum, K);
            
            nextBucketMaxSubsetSum = max(nextBucketMaxSubsetSum, sum[new_mask]);
            
            ans = min(ans, nextBucketMaxSubsetSum);
            
        }
        
        
        return memo[idx][availMask] = ans;
        
        
    }
    
    int minimumTimeRequired(vector<int>& jobs, int k) {
        
        int N= jobs.size();
        vector<vector<int>> memo (k+1, vector<int> (1<<N, -1));

        
        vector<int> sum((1<<N), 0);
        for(int mask =0; mask<(1<<N); mask++){
            for(int i=0; i<N; i++){
                if(mask&(1<<i)){
                    sum[mask]+=jobs[i];
                }
            }
        }
        
        
        //idx, memo, jobs, mask, k
       return dfs(k, (1<<N)-1, memo, jobs, sum, k);
        
        
    }
};