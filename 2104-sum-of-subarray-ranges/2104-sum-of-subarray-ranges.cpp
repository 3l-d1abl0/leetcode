class Solution {
public:
    
    struct Arr{
        int lmin, rmin;
        int lmax, rmax;
    };
    
    void getSmallest(vector<int> &nums, struct Arr *ans){
        
        stack<int> st;
        
        for(int i=0; i<nums.size(); i++){
            
            while(!st.empty() && nums[st.top()] > nums[i]){
                ans[st.top()].rmin = i- st.top();
                st.pop();
            }

            if(!st.empty())
                ans[i].lmin = i - st.top();
                
            st.push(i);
        }
        
    }
    
    
    void getGreatest(vector<int> &nums, struct Arr *ans){
        
        stack<int> st;
        
        for(int i=0; i<nums.size(); i++){
            
            while(!st.empty() && nums[st.top()] < nums[i]){
                ans[st.top()].rmax = i- st.top();
                st.pop();
            }

            if(!st.empty())
                ans[i].lmax = i - st.top();
                
            st.push(i);
        }
    }
    
    long long subArrayRanges(vector<int>& nums) {
        
        Arr ans[nums.size()];
        
        for(int i=0; i<nums.size(); i++){
            ans[i].lmin = ans[i].lmax =(i+1);
            ans[i].rmin = ans[i].rmax = nums.size()-i;
        }
        
        getSmallest(nums, ans);
        getGreatest(nums, ans);
        
        long int diff =0;
        for(int i=0; i<nums.size(); i++){
            
                diff -= (long int)nums[i]*ans[i].lmin*ans[i].rmin;
                diff += (long int)nums[i]*ans[i].lmax*ans[i].rmax;
        }
        
        return diff;
    }
};