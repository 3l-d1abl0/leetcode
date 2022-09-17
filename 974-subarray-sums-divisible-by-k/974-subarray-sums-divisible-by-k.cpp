class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
        
        int sum =0;
        unordered_map<int, int> mp { {0,1} };
        int ans =0;
        for(int ele: nums){
            sum +=ele;
            ans+= mp[((sum%k)+k)%k];
            mp[((sum%k)+k)%k]++;
        }
        
        return ans;
    }
};