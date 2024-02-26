class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
     
        
        int maxLen = INT_MIN;
        
        int onesCount =0;
        
        int lf=0, rt=0;
        for(int rt=0; rt<nums.size(); rt++){
            
            if(nums[rt]==1)
                onesCount++;
            
            
            //if widow needs to be shortened
            int zeros = (rt-lf+1) - onesCount;
            if(zeros>k){
                
                if(nums[lf]==1)
                    onesCount--;
                
                lf++;
            }
            
            
            //Check for the lenth if zeros under replacement
            zeros = (rt-lf+1) - onesCount;
            if(zeros<=k){
                maxLen = max(maxLen, rt-lf+1);
            }
            
            
        }//for
        
        
        return maxLen;
    }
};