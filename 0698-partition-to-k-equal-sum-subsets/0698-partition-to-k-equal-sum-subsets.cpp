class Solution {
public:
    
    
    bool recur(int i, int subsetSum, int k, vector<int> &nums, int currentSum, vector<bool> &taken){
        
        if(k==0)    //the sunset for rest k groups have been found
            return true;
        
        if(subsetSum==currentSum) // found one subset sum, find next
            return recur(0, subsetSum, k-1, nums, 0, taken);
        
        
        for(int idx=i; idx<nums.size(); idx++){
            
            if(taken[idx]== true || currentSum+nums[idx]>subsetSum)
                continue;
            
            taken[idx] = true;
            if ( recur(idx+1, subsetSum, k, nums, currentSum+nums[idx], taken) )
                return true;
            
            taken[idx] = false;
        }
        
        
        return false;
    }
    
    bool method1(vector<int> &nums, int k){
        
        int totalSum =0;
        totalSum = accumulate(nums.begin(), nums.end(), totalSum );
        
        if(totalSum <k || totalSum%k !=0 )
            return false;
        
        vector<bool> taken(nums.size(), false);
        
        //sort(nums.begin(), nums.end());
        
        return recur(0, totalSum/k, k, nums, 0, taken);
        
    }
    
    
bool method2(vector<int> &nums, int k){
        
        int totalSum =0;
        totalSum = accumulate(nums.begin(), nums.end(), totalSum );
        
        if(totalSum <k || totalSum%k !=0 )
            return false;
        
        int N = nums.size();
        int sz = 1<<N;
        
        vector<int> dp(sz, -1);
        
        int subsetSum = totalSum/k;
        
        
        dp[0]=0; //we can alwasy make zero
        for(int mask=0; mask<sz; mask++){

            if(dp[mask]==-1)
                continue;
            
            for(int i=0; i<N; i++){
                
                if( !(mask & (1<<i)) && dp[mask] +nums[i] <= subsetSum ){
                    
                    
                    int new_mask = (mask | (1<<i));   //new state/ mask - set the ith bit
                    
                    dp[new_mask] = (dp[mask]+nums[i])%subsetSum;
                }
                
            }//for i
        
        }//for mask
        
        return dp[sz-1]==0;
    }
    
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        
        
        /*
            1. Recursion
            find a combination subset for K=1,
            When found , try to look
            for combination subset for next group
            i.e. k=2,
            If not able to find any combo for K=2
            look for new combo in K=1, then try for k=2
        */
        
        //return method1(nums, k);
        
        
        return method2(nums, k);
    }
};