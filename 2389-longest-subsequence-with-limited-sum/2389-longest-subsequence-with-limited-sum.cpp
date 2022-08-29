class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& q) {
        
        
        sort(nums.begin(), nums.end());
        
        for(int i = 1; i < nums.size(); i++){
            nums[i] += nums[i-1];
        }
        
        vector<int> ans;
        
        for(int i=0; i< q.size(); i++){
            
            int idx, sum = 0;
            
            for(idx = 0; idx < nums.size(); idx++){
                if(sum + nums[idx] > q[i]) break;
            }
            
            ans.push_back(idx);
        }
        return ans;
    }
};