class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int sm = nums[i], lg = nums[i];
            for (int j = i + 1; j < nums.size(); ++j) {
                sm = min(sm, nums[j]);
                lg = max(lg, nums[j]);     
                res += lg - sm;
            }
        }
        return res;
    }
};