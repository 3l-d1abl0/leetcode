class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        
        int N = nums.size();
        
        vector<int> lis(N,1);
        vector<int> cnt(N,1);
        
        int max_len =1;
        
        for(int i=1; i<N; i++){
            
            for(int j=0; j<i; j++){
                    
                if(nums[i] > nums[j]){
                    
                    if(lis[j]+1 >lis[i]){
                        lis[i] = lis[j]+1;
                        cnt[i] = cnt[j];
                    }else if(lis[j]+1 == lis[i]){
                        cnt[i] +=cnt[j];
                    }
                }
            }
            
            max_len = max(max_len, lis[i]);
            
        }
        
        //check the count of max len
        int ans =0;
        for(int i=0; i<N; i++){
            
            if(max_len == lis[i]){
                ans += cnt[i];
            }
            
        }
        
        return ans;
    }
};