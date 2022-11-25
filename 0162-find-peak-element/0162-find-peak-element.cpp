class Solution {
public:
    
    int BS(vector<int> &nums, int st, int ed){
        
        if(st<ed){
            
            int mid = st +(ed-st)/2;
            
            if(nums[mid] > nums[mid+1]){
                return BS(nums, st, mid);
            }else{
                return BS(nums, mid+1, ed);
            }
            
        }
        
        return st;
    }
    
    
    int BSItr(vector<int> &nums, int st, int ed){
        
        int l=0, r= nums.size()-1;
        
        while(l<r){
            
            int mid = l +(r-l)/2;
            
            if(nums[mid]>nums[mid+1]){ //descending
                r=mid;
            }else{
                l=mid+1;
            }
            
        }
        
        return l;
    }
    
    int findPeakElement(vector<int>& nums) {
        
        int st =0; int ed = nums.size()-1;
        
        
        //return BS(nums, st, ed);
        return BSItr(nums, st, ed);
    }
};