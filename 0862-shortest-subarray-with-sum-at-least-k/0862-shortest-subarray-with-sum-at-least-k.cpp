class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        
        int n = nums.size();
        
        map<long, int> map;
        map.insert({0, -1});
        
        long sum = 0;
        int res = INT_MAX;
        for(int i = 0; i < n; i++)  {
            sum += nums[i];
            map[sum] = i;
                
            auto itUB = map.upper_bound(sum - k);

            if(itUB == map.begin()) continue;

            for(auto it = map.begin(); it != itUB; it++)
                res = min(res, i - it->second);

            map.erase(map.begin(), itUB);       
        }
        
        return res == INT_MAX ? -1 : res;
        
        
    }
};