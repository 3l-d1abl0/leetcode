class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        
        int nextPos =1;
        int ctr =1;
        
        for(int i=1; i<nums.size(); i++){
            
            if(nums[nextPos -1]!= nums[i]){
                nums[nextPos] = nums[i];
                nextPos++;
                ctr=1;
            }else{
                if(ctr==1){
                    nums[nextPos] = nums[i];
                    nextPos++;
                    ctr=0;
                }
                    
            }
        }
        
        return nextPos;
    }
};