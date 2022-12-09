class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        
        
        sort(nums.begin(), nums.end());
        int N = nums.size();
        
        int i=0, j=1;
        
        
        int ctr=0;
        while(j<N){
            
            //skip same elements
            while(j < (N-1) && nums[j]==nums[j+1]){
                j++;
            }
            
            int diff = abs(nums[j]- nums[i]);
            
            if(diff==k){
                ctr++;
                
                i++, j++;
            }else if(diff < k){
                j++;
            }else{
                i++;
            }
            
            if (i == j)
			    j++;
		
            
        }
        
        
        return ctr;
    }
};