class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        
        deque<int> dq;
        vector<int> ans;
        for(int i=0; i<nums.size(); i++){
            
            //remove out of range elements
            while(!dq.empty() && dq.front() <= i-k)
                dq.pop_front();
            
            //remove the smaller number before ele
            while(!dq.empty() && nums[dq.back()] <nums[i]){
                dq.pop_back();
            }
            //put the element
            dq.push_back(i);
            
            if(i>=k-1)
                ans.push_back(nums[dq.front()]);
        }
        
        
        return ans;
    }
};