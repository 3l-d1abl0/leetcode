class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int lo =0, mid =0, hi = nums.size()-1;
        
        while(mid<=hi){
            
            if(nums[mid] ==0){
                swap(nums[lo], nums[mid]);
                lo++;
                mid++;
            }else if(nums[mid]==2){
                swap(nums[hi], nums[mid]);
                hi--;
            }else{
                mid++;
            }
            
        }
    }
};