class Solution {
public:
    
    vector<int> method1(vector<int>& nums) {
        
        int N = nums.size();
        
        vector<int> idx(32,0);
        vector<int> ans(N);
        
        for(int i=N-1; i>=0; i--){
            
            int maxx =i;
            for(int j=31; j>=0; j--){
                
                if((nums[i]>>j)&1)
                    idx[j] =i;
                
                maxx = max(maxx, idx[j]);
            }
            
            ans[i] = maxx-i+1;
        }
        
        return ans;
        
    }
    
    
    vector<int> method2(vector<int> &nums){
        
                
            vector<int> ans;
            int N=nums.size();
            vector<int> nearest (32, -1);

            for (int i = N-1; i >= 0; i--){
                
                for (int j = 0; j < 32; j++) {

                    // Nearest index where jth
                    // bit is set 
                    if (nums[i] & (1 << j))
                            nearest[j] = i;

                }

                int last_set_bit_index = i;

                // Finding Maximum index of all set bits
                for (int j = 0; j < 32; j++)
                last_set_bit_index = max(last_set_bit_index, nearest [j]);

                ans.push_back(last_set_bit_index - i + 1);

            }//for

            // Reversing the answer vector 
            reverse (ans.begin(), ans.end()); return ans;
        
        
            return ans;
        
    }
    
    vector<int> smallestSubarrays(vector<int>& nums) {
        
        
        //return method1(nums);
        return method2(nums);
    }
};