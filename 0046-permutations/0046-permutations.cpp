class Solution {
public:
    
    void method2(vector<int>& nums, vector<vector<int>> &ans, int idx) {
        
        
        if(idx==nums.size()){    
            ans.push_back(nums);
            return;
        }
        
        
        for(int i=idx; i<nums.size(); i++){
            
            swap(nums[idx], nums[i]);
            method2(nums, ans, idx+1);
            swap(nums[idx], nums[i]);
        }
        
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> ans;
        
        //2. Method 2
        method2(nums, ans, 0);
        
        return ans;
    }
};