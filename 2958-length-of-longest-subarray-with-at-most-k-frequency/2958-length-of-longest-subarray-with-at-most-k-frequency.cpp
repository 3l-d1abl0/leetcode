class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        
        
        int lf =0, len =-1;
        unordered_map<int, int> freq;
        
        for(int rt=0; rt<nums.size();rt++){
            
            //process the incoming element
            freq[nums[rt]]++;
            
            //Shrink if the freq of incomg element makes it more than k
            while(freq[nums[rt]] >k){
                freq[nums[lf]]--;
                lf++;
            }
            
            
            
            len = max(len, rt-lf+1);
            
        }//for
        
        
        
        return len;
    }
};