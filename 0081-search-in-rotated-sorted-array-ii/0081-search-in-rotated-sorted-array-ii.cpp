class Solution {
public:
    
    bool rotatedBSItr(vector<int> &nums, int target, int l, int r){
        
        while(l<r){
            
            int mid = l+(r-l)/2;
            
            if(nums[mid]==target)
                return true;
            
            if(nums[l]==nums[mid] && nums[mid]==nums[r]){
                l++;
                r--;
            }else if(nums[l]<=nums[mid]){//ledt side is sorted
                
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
            
        }
        //l==r
        //cout<<l<<" "<<r<<endl;
        if(nums[l]==target)
            return true;

        else
            return false;
    }
    
    bool search(vector<int>& nums, int target) {
        
        int l=0, r=nums.size()-1;
        
        return rotatedBSItr(nums, target, l, r);
    }
};