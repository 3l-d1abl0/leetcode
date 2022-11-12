class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        
        
        sort(nums.begin(), nums.end());
        unordered_set<float> st;
             
             
        int i=0, j = nums.size()-1;
             
             
        while(i<=j){
            
            float avg = (nums[i]+nums[j])/2.0;
            
            st.insert(avg);
            i++; j--;
        }
             
             
        return st.size();
    
    }
};