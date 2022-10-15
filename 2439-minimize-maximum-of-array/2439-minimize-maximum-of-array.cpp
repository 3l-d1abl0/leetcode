class Solution {
public:

    int minimizeArrayValue(vector<int>& nums) {
        int n=nums.size() ;
        vector<long long int> pre(n,0) ;
        
        pre[0] = nums[0] ;
        for(int i=1 ; i<n ; i++)    pre[i] = pre[i-1] + nums[i] ;
        
        long long int ans=0 ;
        for(int i=0 ; i<n ; i++)
        {
            double d=i+1 ;
            double x = pre[i] / d ;
            long long int mx = ceil(x) ;
            ans = max( ans , mx ) ;
        }
        return ans ;
    }
};