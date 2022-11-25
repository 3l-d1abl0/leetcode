class Solution {
public:
    
    int minBS(vector<int> &nums, int st, int ed){
        
        if(nums[st]>nums[ed]){
            
            int mid = st + (ed-st)/2;
            
            if(nums[mid]>nums[ed]){
                return minBS(nums, mid+1, ed);
            }else{
                return minBS(nums, st, mid);
            }
            
        }else
            return nums[st];
        
        
    }
    
    int minBSItr(vector<int> &nums, int l, int r){
        
        while(nums[l]> nums[r]){
            
            int mid = l+(r-l)/2;
            
            if(nums[mid]<=nums[r])
                r=mid;
            else
                l=mid+1;
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