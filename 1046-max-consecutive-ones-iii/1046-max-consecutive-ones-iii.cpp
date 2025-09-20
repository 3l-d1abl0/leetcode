class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
     
        
        int maxLen = INT_MIN;
        int zerosCount =0;
        
        int lf=0, rt=0;
        for(int rt=0; rt<nums.size(); rt++){
            
            if(nums[rt]==0)
                zerosCount++;
            
            while(zerosCount>k){
                if(nums[lf]==0)
                    zerosCount--;
                
                lf++;
            }
            
            
            //zeros<=k
                maxLen = max(maxLen, rt-lf+1);

            
        }//for
        
        
        return maxLen;
    }
};