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
    
    
    int method2(vector<int> &nums, int goal){
        
        int lf=0, subarray=0;
        int sum=0, ans =0;
        
        
        for(int rt=0; rt<nums.size(); rt++){
            
            if(nums[rt]==1){
                sum++;
                subarray=0;
            }
            
            
            while(sum==goal){
                
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
  
        //TC: O(N) SC O(N)
        return method1(nums, goal);
        
        //TC
        return method2(nums, goal);
    }
};