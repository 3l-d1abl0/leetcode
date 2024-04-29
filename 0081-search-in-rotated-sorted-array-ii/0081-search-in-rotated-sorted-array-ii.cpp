class Solution {
public:
    
        int rotatedBSItr(vector<int> &nums, int target, int l, int r){
        
        while(l<=r){
            
            int mid = l+(r-l)/2;
            
            //cout<<mid<<" "<<nums[mid]<<" tar"<<target<<endl;
            if(nums[mid]==target)
                return true;
            
            /*
                [1,0,1,1,1]
                0
                Shrink the search Space
            */
            if(nums[l]==nums[mid] && nums[mid]==nums[r]){
                l = l+1;
                r = r-1;
                continue;
            }
            
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
        
         return false;
    }
    
    bool search(vector<int>& nums, int target) {
        
        int st = 0, ed = nums.size();
        
        
        return rotatedBSItr(nums, target, st, ed-1);
        
    }
};