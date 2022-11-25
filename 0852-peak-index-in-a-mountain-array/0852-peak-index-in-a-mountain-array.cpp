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
    
    
    int BSNew(vector<int> &nums, int st, int ed){
        
        while(st<ed){
            
            int mid = st+(ed-st)/2;
            
            if(nums[mid]>nums[mid+1]){
                ed = mid;
            }else{
                st = mid+1;
            }
        }
        
        //st==ed
        return st;
        
        
    }
    
    int peakIndexInMountainArray(vector<int>& nums) {
                int st =0; int ed = nums.size()-1;
        
        
        //return BS(nums, st, ed);
        
        return BSNew(nums, st, ed);
    }
};