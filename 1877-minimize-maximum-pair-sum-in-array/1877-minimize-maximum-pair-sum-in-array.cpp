class Solution {
public:
    int minPairSum(vector<int>& nums) {
        
        
        sort(nums.begin(), nums.end());
        
        int l =0, r = nums.size()-1;
        
        int maxx =-1;
        while(l<r){
            
            maxx = max(maxx, nums[l]+nums[r]);
            l++; r--;
        }
        
        
        return maxx;
        
    }
};