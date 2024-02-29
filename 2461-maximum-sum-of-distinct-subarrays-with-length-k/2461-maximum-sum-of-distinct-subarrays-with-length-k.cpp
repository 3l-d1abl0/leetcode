class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        
        unordered_map<int ,int> m;
        long long ans = 0, s = 0, i = 0;
        
        for(int j=0; j<nums.size(); j++) {
            m[nums[j]]++;
            s += nums[j];
            if(k == j - i + 1) {
                if(m.size() == k) ans = max(ans, s);
                s -= nums[i];
                m[nums[i]]--;
                if(!m[nums[i]]) m.erase(nums[i]);
                i++;
            }
        }
        return ans;
    }
};