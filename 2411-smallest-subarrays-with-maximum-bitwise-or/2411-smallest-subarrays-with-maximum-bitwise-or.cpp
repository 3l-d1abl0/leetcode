class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        
        int N = nums.size();
        
        vector<int> idx(32,0);
        vector<int> ans(N);
        
        for(int i=N-1; i>=0; i--){
            
            int maxx =i;
            for(int j=31; j>=0; j--){
                
                if((nums[i]>>j)&1)
                    idx[j] =i;
                
                maxx = max(maxx, idx[j]);
            }
            
            ans[i] = maxx-i+1;
        }
        
        return ans;
    }
};