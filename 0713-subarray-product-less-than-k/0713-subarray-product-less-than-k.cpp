class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        
        int N = nums.size();
        long long int prod = 1;
        int ans =0;
        
        for(int lf=0, rt=0; rt<N; rt++){
        
            prod *= nums[rt];
            
            while(prod>=k && lf<=rt){
                prod/=nums[lf];
                lf++;
            }
            
            
            ans += (rt-lf+1);
            
        }
        
        
        return ans;
        
        
    }
};