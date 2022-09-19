class Solution {
public:
    int method1(vector<int>& nums){
        
        int ans =0;
        for(int ele: nums){
            ans |= ele;
        }
        
        return ans;
        
    }
    
    int maximumXOR(vector<int>& nums) {
        
        
        return method1(nums);
    }
};