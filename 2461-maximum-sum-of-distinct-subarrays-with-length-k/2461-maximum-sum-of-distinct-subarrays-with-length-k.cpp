class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
     
        
        
        unordered_set<int> mp;
        int N = nums.size();
        
        int lf =0;
        long long int ans=0, sum =0;
                          
        for(int rt =0; rt< N; rt++){
            
            int inEle = nums[rt];
            
            
            //If the incoming window already exists, shrink th window, till its last occurance
            while(lf < rt && mp.count(inEle) !=0){
                mp.erase(nums[lf]);
                sum -= nums[lf];
                lf++;
            }
            
            //Include it in the current window
            sum += inEle;
            mp.insert(inEle);
            
            
            //churn elemets from left if  the window size is >=k    
            while(lf<rt && mp.size() >k  ){
                mp.erase(nums[lf]);
                sum -= nums[lf];
                lf++;
            }
            
            
            if(mp.size() ==k)
                ans = max(ans, sum);
        }//for
                              
        
        
        return ans;
    }
};