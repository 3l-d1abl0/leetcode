class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        
        int maxx = *max_element(nums.begin(), nums.end());
        
        int maxlen = 0, ctr =0;
        
        for(int ele: nums){
            if(maxx == ele) ctr++;
            else ctr=0;
            
            maxlen = max(maxlen, ctr);
        }
        
        
        return maxlen;
    }
};