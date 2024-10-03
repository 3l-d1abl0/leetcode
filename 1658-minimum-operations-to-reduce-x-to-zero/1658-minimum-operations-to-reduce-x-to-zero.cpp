class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        
        /*
        |------------------SUM-------------------|
        |----------[-------SUM-X--------]--------|
        |----------[                    ]--------|
             X1                              X2
             
             
        X = X1+X2
        */
        
        
        int N = nums.size();
        long long int sum = accumulate(nums.begin(), nums.end(), 0);
        long long int reqSum = sum - x;

        int maxLength = -1, currSum = 0;
        for (int l=0, r=0; r<nums.size(); r++) {
            
            currSum += nums[r];
            while (l <= r && currSum > reqSum)
                currSum -= nums[l++];
            
            if (currSum == sum - x)
                maxLength = max(maxLength, r-l+1);
        }

        return maxLength == -1 ? -1 : N - maxLength;
        
        
    }
};



