class Solution {
public:
    
    int minBS(vector<int> & nums, int st, int ed){
        
        if(nums[st]>=nums[ed]){  //rotated array
            
            if(st<ed){
            
                int mid = st +(ed-st)/2;

                if(nums[mid] > nums [ed]){

                    return minBS(nums, mid+1, ed);

                }else if(nums[mid] < nums [ed]){
                    return minBS(nums, st, mid);
                }else{
                    return minBS(nums, st, ed-1);
                }
                    
            
            }else 
                return nums[ed];
            
            
        }else{
            return nums[st];
        }
    }
    
    
    int findMin(vector<int>& nums) {
        
        int st =0, ed= nums.size()-1;
        
        return minBS(nums, st, ed);
        
    }
};