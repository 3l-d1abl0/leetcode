class Solution {
public:
    int rob(vector<int>& nums) {
     
            int N = nums.size();
        
        
            int prev2 =0;
            int prev1 = nums[0];
            
            for(int i=1; i<N; i++){
                    
                int include = nums[i];
                    
                if(i>1)
                    include +=prev2;
                
                int exclude = prev1;
                
                int current = max(include, exclude);
                
                prev2 = prev1;
                prev1 = current;
            }
        
        return prev1;
    }
};