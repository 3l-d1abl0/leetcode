class Solution {
public:
    int f(vector<int> &nums, int idx, vector<int> &dp){
        
        if(idx>=nums.size()-1)  return 0;
        
        if(dp[idx]!=1e4+10) return dp[idx];
        
        for(int i=1; i<=nums[idx]; i++){
            dp[idx] = min(dp[idx], f(nums, idx+i, dp)+1);
        }
        
        return dp[idx];
    }
    
    /*int jump(vector<int>& nums) {
        
        vector<int> dp(nums.size(), 1e4+10);    //max possible jump - linear
        return f(nums, 0, dp);
        
    }*/
    
    
    int jump(vector<int>& nums) {
	int n = size(nums);
	vector<int> dp(n, 10001);
	dp[n - 1] = 0;  // start from last index. No jumps required to reach end if we are already here
	// same as above. For each index, explore all jump sizes and use the one requiring minimum jumps to reach end
	for(int i = n - 2; i >= 0; i--) 
		for(int jumpLen = 1; jumpLen <= nums[i]; jumpLen++) 
			dp[i] = min(dp[i], 1 + dp[min(n - 1, i + jumpLen)]);  // min(n-1, i + jumpLen) for bounds handling
	return dp[0];
}
};