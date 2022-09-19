class Solution {
public:
    int maximumXOR(vector<int>& nums) {
        
        int ans =0;
        for(int ele: nums){
            ans |= ele;
        }
        
        return ans;
    }
};