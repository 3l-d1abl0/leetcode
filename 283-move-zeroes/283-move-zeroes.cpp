class Solution {
public:
    void moveZeroes(vector<int>& nums) {
     
        
        int zI = -1; 
        
        for(int i=0; i<nums.size(); i++){
            
            
            if(nums[i]==0){
                
                if(zI==-1) zI= i;
            }else{
                if(zI!=-1){
                    swap(nums[zI], nums[i]);
                    zI++;
                }
            }
            
        }
        
    }
};