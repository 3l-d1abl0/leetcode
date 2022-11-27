class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        
        sort(nums.begin(), nums.end());
        
        int lf =0, rt=0, ans =0;
        int N = nums.size();
        long long int sum =0;
        
        for(int rt=0; rt<N; rt++){
            
            sum += nums[rt];
            while(1ll*nums[rt]*(rt-lf+1) - sum >k){
                sum-=nums[lf];
                lf++;
            }
            
            //cout<<rt<<" "<<lf<<rt-lf+1<<endl;
            ans = max(ans, rt-lf+1);
        }
        
        
        return ans;
    }
};