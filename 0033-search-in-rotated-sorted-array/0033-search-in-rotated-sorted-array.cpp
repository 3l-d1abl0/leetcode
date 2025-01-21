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
                return rotatedBS(nums, target, mid+1, ed);
            
            
        }else{
            
            if(target > nums[mid] && target <= nums[ed])
                return rotatedBS(nums, target, mid+1, ed);
            else
                return rotatedBS(nums, target, st, mid-1);
            
            
        }
        
        
    }
    
    int rotatedBSItr(vector<int> &nums, int target, int l, int r){
        
        while(l<=r){
            
            int mid = l+(r-l)/2;
            
            if(nums[mid]==target)
                return mid;
            
            if(nums[l]<=nums[mid]){//ledt side is sorted
                
                if(nums[l]<=target && target< nums[mid])
                    r= mid-1;
                else
                    l=mid+1;
                
            }else{  //right side is sorted
                
                if(nums[mid]<target && target <=nums[r])
                    l=mid+1;
                else
                    r=mid-1;
            }
            
        }//while
        
         return -1;
    }
    
    int search(vector<int>& nums, int target) {
        
        //Look in the sorted part of the Array, else fix indexes for the unsorted part
        
        
        int st = 0, ed = nums.size();
        
        //return rotatedBS(nums, target, st, ed-1);
        
        return rotatedBSItr(nums, target, st, ed-1);
        
    }
};