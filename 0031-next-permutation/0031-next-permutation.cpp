class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int N = nums.size();
            
        //1. Find a point i from back such that [i]<[i+1]
        int i=-1;
        for(i=N-2; i>=0; i--){
            
            if(nums[i]<nums[i+1])
                break;
        }
        
        if(i==-1){//not founf , whole num is descending order
            
            reverse(nums.begin(), nums.end());
            return;
        }
        
        for(int j=N-1; j>i; j--){
            
            if(nums[j]>nums[i]){
                swap(nums[i], nums[j]);
                break;
            }
        }

        
        reverse(nums.begin()+i+1, nums.end());
        
        
    }
};