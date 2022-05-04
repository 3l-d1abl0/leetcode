class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
     
        int N = nums.size();
        
        int minLen = 1e9;
        long long sum =0;
        int left=0;
        for(int right=0; right<N; right++){
            
            sum += nums[right];
            
            while(sum>=target){
                minLen = min(minLen, right-left+1);
                sum -= nums[left];
                left++;
                cout<<minLen<<" ";
            }
        }
        
        
        if(minLen==1e9)
            return 0;
        else
            return minLen;
        
    }
};