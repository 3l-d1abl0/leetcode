class Solution {
public:
    
    int method2(vector<int> &nums){
        
        //https://leetcode.com/problems/max-chunks-to-make-sorted/discuss/595709/Monotonic-stack-solution-with-detailed-explanation
        
        int ctr =0;
        stack<int> st;
        
        int largest;
        for(int i= 0; i<nums.size(); i++){
            
            largest = nums[i];
            
            while(!st.empty() && st.top() > nums[i]){
                largest  = max(largest, st.top());
                st.pop();
            }
            
            st.push(largest);
            
        }
            
        return st.size();
        
        
    }
    
    int method1(vector<int> &nums){
                
        int maxx = INT_MIN;
        int chunk =0;
        
        for(int i=0 ;i<nums.size(); i++){
            
            maxx = max(maxx, nums[i]);
            
            if(maxx==i)
                chunk ++;
        }
        
        return chunk;
    }
    
    int maxChunksToSorted(vector<int>& nums) {
        
        return method1(nums);
        //return method2(nums);
    }
};