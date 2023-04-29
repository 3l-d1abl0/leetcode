class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        
        /*Reusing the 3sum concept
        
            TC: O(NlogN) + O(N^2)
            
            
        */
        
        int N = nums.size();
        
        sort(nums.begin(), nums.end());
        
        int minDiff = 1e9;
        int minSum;
        
        for(int i=0; i<N-1; i++){
            
            if(i>0 && nums[i] == nums[i-1] )    //pick unique i
                continue;
            
            
            int lf=i+1;
            int rt=N-1;
            
            
            while(lf < rt){
                
                
                int sum = nums[i]+nums[lf]+nums[rt];
                
                if(sum == target)
                    return sum;
                
                
                if( abs(sum-target) < minDiff){
                    minDiff = abs(sum-target);
                    minSum = sum;
                }
                
                
                if(sum > target){
                    rt--;
                }else{
                    lf++;
                }
                
            }//while
            
        }//for
        
        return minSum;
    }
};