class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        int N = nums.size();
        
        int l=0, r= N-1;
        
        if(r==0)    //arrary size 1
            return nums[r];
        else if(nums[l]!=nums[l+1])
            return nums[l];
        else if(nums[r-1]!=nums[r])
            return nums[r];
        
        
        while(l<=r){
            
            int mid = l+(r-l)/2;
            
            /*before:
                even - 1st idx
                odd- end idx
                
            single -  even idx
            
            after:
                even - 2nd idx 
                odd - 1st Idx
            */
            
            
            if(nums[mid]!= nums[mid-1] && nums[mid]!=nums[mid+1])
                return nums[mid];
            
            if(mid%2==0 && nums[mid] == nums[mid+1])
                l= mid+1;
            else if(mid%2==0 && nums[mid] != nums[mid+1])
                r= mid-1;
            
            
            if(mid%2==1 && nums[mid] == nums[mid-1])
                l= mid+1;
            else if(mid%2==1 && nums[mid] != nums[mid-1])
                r= mid-1;
            
            
        }//while
        
        
        return -1;
    }
};