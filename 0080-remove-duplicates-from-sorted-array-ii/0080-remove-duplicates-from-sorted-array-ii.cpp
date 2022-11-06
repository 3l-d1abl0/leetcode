class Solution {
public:
    
    int method1(vector<int>& nums) {
        
        
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
    
    
    int removeDuplicates(vector<int>& nums) {
        
        
        
        return method1(nums);
        
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