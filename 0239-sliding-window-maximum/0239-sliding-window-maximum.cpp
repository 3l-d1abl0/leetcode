class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        
        deque<int> dq;
        vector<int> ans;
        /*
            use a dqque to maintain the window.
            as soon a greater elements enter the window from the right,
            the lesser  elements on the left has no chance to become the
            max number because of a greater number on the right
            
            so keep popping the numbers from left if the are less than in coming element
        */
        for(int i=0; i<nums.size(); i++){
            
            //1. remove out of range elements
            while(!dq.empty() && dq.front() <= i-k)
                dq.pop_front();
            
            //2. remove the smaller number before ele
            while(!dq.empty() && nums[dq.back()] <nums[i]){
                dq.pop_back();
            }
            
            //3. put the element
            dq.push_back(i);
            
            //4. limit to start print the window
            if(i>=k-1)
                ans.push_back(nums[dq.front()]);
        }
        
        
        return ans;
    }
};