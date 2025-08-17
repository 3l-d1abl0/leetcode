class Solution {
public:

    int method1(vector<int>& nums, int k) {


        int maxx =0;
        int lf=0;
        unordered_map<int, int> mp;
        for(int rt=0; rt<nums.size(); rt++){
            
            //Increase the count of incoming element
            mp[nums[rt]]++;
            
            //shrink the window from the left until the zero count in less than k
            while(mp[0]>k){
                
                mp[nums[lf]]--;
                lf++;
            }
            
            //If zero count is less than eq k
            if(mp[0]<=k)
                maxx = max(maxx, rt-lf+1);
            
            
        }//for
        
        return maxx;
    }


    int method2(vector<int>& nums, int k) {

        int maxLen = INT_MIN;
        
        int onesCount =0;
        
        int lf=0, rt=0;
        for(int rt=0; rt<nums.size(); rt++){
            
            if(nums[rt]==1)
                onesCount++;
            
            
            //if widow needs to be shortened
            int zeros = (rt-lf+1) - onesCount;
            if(zeros>k){
                
                if(nums[lf]==1)
                    onesCount--;
                
                lf++;
            }
            
            
            //Check for the lenth if zeros under replacement
            zeros = (rt-lf+1) - onesCount;
            if(zeros<=k){
                maxLen = max(maxLen, rt-lf+1);
            }
            
            
        }//for
        
        
        return maxLen;
    }


    int longestOnes(vector<int>& nums, int k) {
        

        //keep count of zero, one via map - 23m
        //return method1(nums, k);



        return method2(nums, k);    //4ms
        

    }
};