class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        
        int maxElement = *max_element(nums.begin(), nums.end());
        
        vector<int> idxMaxElement;
        long long int ans = 0;
        
        for(int idx=0; idx<nums.size(); idx++){
            
            if(nums[idx] == maxElement)
                idxMaxElement.push_back(idx);
            
            int N = idxMaxElement.size();
            if(N>=k){
                
                ans +=idxMaxElement[N-k]+1;
            }
        }//for
        
        
        return ans;
        
    }
};