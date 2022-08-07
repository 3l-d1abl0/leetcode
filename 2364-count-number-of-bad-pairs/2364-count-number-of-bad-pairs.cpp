class Solution {
public:
    long long method1(vector<int> &nums){
        
        unordered_map<int, int> mp;
        long long ans =0;
        for(int i=0; i<nums.size(); i++){
            
            ans += i- mp[nums[i]-i];
            mp[nums[i]-i]++;
        }
        
        
        return ans;
    }
    
    long long countBadPairs(vector<int>& nums) {
        
        
        return method1(nums);
    }
};