class Solution {
public:
    
    int minBS(vector<int> &nums, int st, int ed){
        
        if(nums[st]>nums[ed]){
            
            int mid = st + (ed-st)/2;
            
            if(nums[st] <= nums[mid]){
                return minBS(nums, mid+1, ed);
            }else{
                return minBS(nums, st, mid);
            }
            
        }else
            return nums[st];
        
        
    }
    
    int minBSItr(vector<int> &nums, int l, int r){
        

        while(nums[l]> nums[r]){
            /* if [l] > [r] it means 
                the rotation point is somewhere in the
                middle, other wise the array [l - r] is already sorted
                with [l] as the minimum
            */
            
            int mid = l+(r-l)/2;
            
            if(nums[l] <= nums[mid])    //if l and mid are the same index, for 2 size ele
                l=mid+1;
            else
                r=mid;  //the mid itself can be the min ele, hence stayed
        }
        
        return nums[l];
        
    }
    
    int findMin(vector<int>& nums) {
        
        
        int st =0;
        int N = nums.size();
        
        //return minBS(nums, st, N-1);
        return minBSItr(nums, st, N-1);
    }
};