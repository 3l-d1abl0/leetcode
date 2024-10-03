class Solution {
public:
    
    int method1(vector<int> &nums, int goal){
        
        if(goal<0)
            return 0;
        
        unordered_map<int, int> map;
        int sum =0, cnt=0;
        for(int i=0; i<nums.size(); i++){
            
            sum += nums[i];
            if(sum==goal)
                cnt++;
            
            //checks for excess sum or zero sum
            if(map.find(sum-goal) != map.end())
                cnt+= map[sum-goal];
            
            
            map[sum]++;
        }
        
        
        return cnt;
    }
    
    int zeroSum(vector<int> &nums) {
        
        int cnt = 0;
        int res = 0;
        
        for ( int i = 0; i < nums.size(); i++ ) {
            if ( nums[i] == 0 ) {
                cnt++;
                res += cnt;
            }
            else {
                cnt = 0;
            }
        }
        return res;
    }
    
    int method2(vector<int> &nums, int goal){
        
        int lf=0, subarray=0;
        int sum=0, ans =0;
        
        if (goal==0)
            return zeroSum(nums);
        
        for(int rt=0; rt<nums.size(); rt++){
            
            if(nums[rt]==1){
                sum++;
                subarray=0;
            }
            
            
            while(sum==goal && lf<=rt){
                
                subarray++;
                
                if(nums[lf]==1)
                    sum--;
                
                lf++;
            }
            
            ans+=subarray;
        }
        
        
        return ans;
    }
    
    int numSubarraysWithSum(vector<int>& nums, int goal) {
  
        //TC: O(N) SC O(N)- Cumulative Sum - MAP
        return method1(nums, goal);
        
        //TC: O(N), SC: O(1) - Sliding Window/2 Pointer - 21ms
        //return method2(nums, goal);
    }
};