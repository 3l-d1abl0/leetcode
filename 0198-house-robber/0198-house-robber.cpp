class Solution {
public:
    
    int recMemo(int idx, vector<int> &nums, vector<int> &memo){
        
        if(idx<0)
            return 0;
        
        if(memo[idx]!=-1)
            return memo[idx];
        
        
        //pick/Include
        int inSum = nums[idx]+recMemo(idx-2, nums, memo);
        
        //not pick //exclude
        int exSum = recMemo(idx-1, nums, memo);
        
        
        return memo[idx] = max(inSum, exSum);
        
    }
    
    int rob(vector<int>& nums) {
        
        int N = nums.size();
        vector<int> memo(N, -1);
        return recMemo(N - 1, nums, memo);
    }
};