class Solution {
public:
    
    int justRob(vector<int>& nums) {
     
            int N = nums.size();
        
        
            int prev2 =0, prev1 = 0, curr =0;
            
            for(int i=0; i<N; i++){
                    
                 curr = max(nums[i]+prev2, prev1);
                
                
                prev2 = prev1;
                prev1 = curr;
            }
        
        return curr;
    }
    
    int rob(vector<int>& nums) {
        
        
        if(nums.size()==0) return 0;
        
        if(nums.size()==1) return nums[0];
        
        
        vector<int> noLast (nums.begin(), nums.end()-1);
        vector<int> noFirst (nums.begin()+1, nums.end());
        
        
        return max(justRob(noLast), justRob(noFirst));
        
    }
};