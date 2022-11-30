class Solution {
public:
    /*
    int twoPointer(int target, vector<int> &nums){
        
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
                //cout<<minLen<<" ";
            }
        }
        
        
        if(minLen==1e9)
            return 0;
        else
            return minLen;

    }
    */
    
    int bSearch(vector<int> &prefixSum, int val, int N){
        
        int l=-1, r=N;
        
        while(r-l>1){
            
            int mid = l+(r-l)/2;
            if(prefixSum[mid]<=val){
                l=mid;
            }else{
                r=mid;
            }
        }
        
        //cout<<l<<" , "<<r<<endl;
        return l;
    }
    
    int binarySearch(int k, vector<int> &nums){
        
        int N = nums.size();
        vector<int> prefixSum(N+1, 0);
        for(int i=1; i<=N; i++)
            prefixSum[i] = prefixSum[i-1]+nums[i-1];
        
        /*for(int ele: prefixSum)
            cout<<ele<<" ";
        cout<<endl;*/
        
        int minLen = INT_MAX;
        int prefix =0;
        for(int i=0; i<N; i++){
            
            prefix +=nums[i];
            /*
                prefixsum[i]-prefixsum[j-1] >= k  //i-j+1
                prefixsum[i]-k  >= prefixsum[j-1]
                find (greatest) num which is lesser than eq to prefixsum[i]-k
            */
            if(prefix>=k){
                //cout<<"i = "<<i<<" p ="<<prefixSum[i+1]<<" val= "<<prefix-k<<endl;
                int idx = bSearch(prefixSum, prefix-k, N+1);
                minLen = min(minLen, i-idx+1);
                //cout<<"len= "<<minLen<<endl;
            }
            
        }
        
        if(minLen==INT_MAX)
            return 0;
        else
            return minLen;
        
    }
    
    int minSubArrayLen(int target, vector<int>& nums) {
             
        
        //return twoPointer(target, nums);
        
        return binarySearch(target, nums);
        
    }
};