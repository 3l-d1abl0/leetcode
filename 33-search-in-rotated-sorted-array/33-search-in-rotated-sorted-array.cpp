class Solution {
public:
    int rotatedBS(vector<int> &nums, int target, int st, int ed){
        
        if(st>ed)   return -1;
        
        int mid = st + (ed-st)/2;
        
        if(target == nums[mid]) return mid;
        
        
        if(nums[st]<=nums[mid]){
            
           if(target>= nums[st] && target<nums[mid])
               return rotatedBS(nums, target, st, mid-1);
            else
                return rotatedBS(nums, target, st+1, ed);
            
            
        }else{
            
            if(target > nums[mid] && target <= nums[ed])
                return rotatedBS(nums, target, mid+1, ed);
            else
                return rotatedBS(nums, target, st, mid-1);
            
            
        }
        
        
    }
    
    int search(vector<int>& nums, int target) {
        
        
        int st = 0, ed = nums.size();
        
        return rotatedBS(nums, target, st, ed-1);
        
    }
};