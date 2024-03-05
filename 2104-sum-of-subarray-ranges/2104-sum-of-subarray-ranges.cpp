class Solution {
public:
    
    struct Arr{
        int lmin, rmin;
        int lmax, rmax;
    };
    
    void getSmallest(vector<int> &nums, vector<Arr> &ans){
        
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
    
    
    void getGreatest(vector<int> &nums, vector<Arr> &ans){
        
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
        
        /*
            Same Logic As : https://leetcode.com/problems/sum-of-subarray-minimums/
        */
        
        //Arr ans[nums.size()];
        
        vector<Arr> ans(nums.size());
        
        for(int i=0; i<nums.size(); i++){
            //default: min and max ele on left
            ans[i].lmin = ans[i].lmax =(i+1);
            
            //default: min and max ele on right
            ans[i].rmin = ans[i].rmax = nums.size()-i;
        }
        
        getSmallest(nums, ans); //on left and right
        getGreatest(nums, ans); //on left and right
        
        long int diff =0;
        for(int i=0; i<nums.size(); i++){
            
                //[i] is minimum in the range l - r
                diff -= (long int)nums[i]*ans[i].lmin*ans[i].rmin;
                //[i] is max in the range l - r 
                diff += (long int)nums[i]*ans[i].lmax*ans[i].rmax;
        }
        
        return diff;
    }
};