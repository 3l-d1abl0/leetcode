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
    
    
    long long method2(vector<int> &nums){
        
        unordered_map<int, int> mp;
        long long cnt =0;
        for(int i=0; i<nums.size(); i++){
            cnt+= mp[nums[i]-i];
            mp[nums[i]-i]++;
        }
        
        return 1LL*nums.size()*(nums.size()-1)/2 - cnt;
    }
    
    long long countBadPairs(vector<int>& nums) {
        
        
        //return method1(nums);
        return method2(nums);
    }
};