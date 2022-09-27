class Solution {
public:
    
    int rec(int i, int target, vector<int> &arr, vector<vector<int>> &memo){
        
        if(target==0)
            return 1;
        
        if(i== arr.size())
                return 0;
        
        if(memo[i][target]!=-1)
            return memo[i][target];
        
        int inc = 0;
        if(arr[i]<=target){
            inc = rec(0, target-arr[i], arr, memo);
        }
        
        int exc = rec(i+1, target, arr, memo);
        
        return memo[i][target] = inc+exc;
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        
        vector<vector<int>> memo(nums.size(), vector<int>(target+1, -1) );
        
        return rec(0, target, nums, memo);
        
    }
};