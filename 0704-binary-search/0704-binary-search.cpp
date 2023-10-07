class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int N = nums.size();
        int left =0; int right = N-1;
        
        while(left <= right){
            
            if(left==right){
                if(nums[left]==target)
                    return left;
                else
                    return -1;
            }else{
                
                
                int mid = left + (right-left/2);
                
                if(nums[mid]==target){
                    return mid;
                }else if (nums[mid]<target){
                    left=mid+1;
                }else{
                    right=mid-1;
                }
                
                
            }//else
            
            
        }//while
        
        
        return -1;
        
    }
};