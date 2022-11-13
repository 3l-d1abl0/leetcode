class Solution {
public:
    
    int subarrayLCM(vector<int>& nums, int k) {
        
        
        int ans = 0;
        int N = nums.size();
        for(int i=0; i<N; i++){
            unsigned int cGcd = nums[i];

            for(int j=i; j<N; j++){
                cGcd = lcm(cGcd, nums[j]);

                ans += (cGcd == k) ? 1 : 0;
            }
        }
        
        
        return ans;
        
    
        
    }
};