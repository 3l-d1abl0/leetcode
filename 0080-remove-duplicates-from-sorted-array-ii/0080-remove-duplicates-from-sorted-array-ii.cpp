class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int lf=0, rt=0;
        int N = nums.size();
        
        
        while(rt<N){
            
            nums[lf] = nums[rt];
            
            if(rt+1<N){
                
                if(nums[rt]==nums[rt+1]){
                    lf++; rt++;
                    nums[lf] = nums[rt];
                }else{
                    lf++; rt++;
                    continue;
                }
            }
            
            while(rt<N && nums[lf]==nums[rt]){
                rt++;
            }
            
            lf++;
            
        }
        
        
        return lf;
        
    }
};