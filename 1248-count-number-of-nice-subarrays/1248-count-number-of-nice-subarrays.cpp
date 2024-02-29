class Solution {
public:
    
    int method1(vector<int>& nums, int k) {
        
        unordered_map<int, int> map;
        
        const int N = nums.size();
        
        int ans = 0;
        int oddCount = 0;
        
        for (int i = 0; i < N; ++i) {
            oddCount += (nums[i]&1);
            
            if(oddCount==k)
                ans++;
            if(map.find(oddCount-k) != map.end())
                ans += map[oddCount-k];
            
            map[oddCount]++;
        }
        
        return ans;
        
    }
    
    
    int method2(vector<int>& nums, int k) {
        
        int lf=0, ans =0;
        int oddCount =0, subarray=0;
        
        for(int rt=0; rt<nums.size(); rt++){
            
            
            if(nums[rt]&1){//If number is odd
                oddCount++;
                //subarray fo far which has oddCount =k
                subarray =0;
            }
            
            
            while(oddCount==k){  //calculate the subarrary with oddCount =k while shrinking
                
                subarray++;
                
                if(nums[lf]&1)
                    oddCount--;
                
                lf++;
            }
            
            
            ans+=subarray;
            //add the trailing subarray till we find the next odd ele
            
        }//for
        
        
        return ans;
    }
    
    int numberOfSubarrays(vector<int>& nums, int k) {
        
        //TC: O(N) SC: O(N)
        //return method1(nums, k);
        
        
        return method2(nums, k);
    }
};