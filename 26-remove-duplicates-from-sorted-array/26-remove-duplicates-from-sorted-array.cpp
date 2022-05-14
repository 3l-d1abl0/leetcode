class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int nextPos =1;
        
        for(int i=1; i<nums.size(); i++){
            
            if(nums[nextPos-1]!=nums[i]){
                nums[nextPos] = nums[i];
                nextPos++;
            }
        }
            
        return nextPos;
    }
};