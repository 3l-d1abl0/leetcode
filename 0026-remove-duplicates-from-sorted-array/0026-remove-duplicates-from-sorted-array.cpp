class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        /*
        int nextPos =1;
        
        for(int i=1; i<nums.size(); i++){
            
            if(nums[nextPos-1]!=nums[i]){
                nums[nextPos] = nums[i];
                nextPos++;
            }
        }
            
        return nextPos;*/
        
       int i=0, ed=0;
        int N= nums.size();
        while(ed<N){
            nums[i] = nums[ed];
            while(ed<N && nums[i]==nums[ed])
                ed++;
            
            i++;
        }
        
        return i;
    }
};