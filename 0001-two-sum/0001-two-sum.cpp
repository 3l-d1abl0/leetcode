class Solution {
public:
    
    vector<int> hashApproach(vector<int> &nums, int target){
        
        unordered_map<int, int> mp;
        vector<int> res;
        
        for(int i=0; i<nums.size(); i++){
            
            if(mp.find(target-nums[i])!=mp.end()){
                
                
                res.push_back(i);
                res.push_back(mp[target-nums[i]]);
                return res;
                
            }
            
            
            mp[nums[i]] =i;
            
        }
        
        
        return res;
    }
    
    vector<int> twoPointer(vector<int> &nums, int target){
        
        int l=0, r= nums.size()-1;
        
        while(l<r){
            
            if(nums[l]+nums[r] == target)
                return vector<int> {l, r};
            
            if(nums[l]+nums[r] > target)
                r--;
            else
                l++;
            
        }
        
        
        return vector<int> {-1, -1};
    } 
    
    vector<int> twoSum(vector<int>& nums, int target) {
        
        //1.hash
        return hashApproach(nums, target);
        
        //2. Two Pointer
        //return twoPointer(nums, target);

    }
};