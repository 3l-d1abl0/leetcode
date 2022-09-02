class Solution {
public:
    
    /*
    Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
    Output: 6
    [1,1,1,0,0,{0,1,1,1,1,0}]
    
    
    Input: nums = [0,0,{1,1,0,0,1,1,1,0,1,1},0,0,0,1,1,1,1], k = 3
    Output: 10
    
    look for longes length with k zero in it
    */
    
    int longestOnes(vector<int>& nums, int k) {
       
        
        int maxx =0;
        int lf=0;
        unordered_map<int, int> mp;
        for(int i=0; i<nums.size(); i++){
            
            mp[nums[i]]++;
            
            while(mp[0]>k){
                
                mp[nums[lf]]--;
                lf++;
            }
            
            
            maxx = max(maxx, i-lf+1);
            
            
        }//for
        
        return maxx;
        
    }
};