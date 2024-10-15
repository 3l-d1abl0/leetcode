class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        
        /*
        
          0 1 2 3 4 5 6 [1 . . . k]
          |     N-k   | +  1
          
          
          1,3,2,3,3
          
          
           0 1 2
          [1 3 4]
          
          0 [ 1 2 3 ]
          1 [ 3 2 3 ]
          1 +[ 1 ] = 2
          
          0 1 2   3  4
          1 3 2 [ 3  3 ]
          
          |--3---| +1   = 4
          
          Total 4+6
        */
        
        int maxElement = *max_element(nums.begin(), nums.end());
        
        vector<int> idxMaxElement;
        long long int ans = 0;
        
        for(int idx=0; idx<nums.size(); idx++){
            
            if(nums[idx] == maxElement)
                idxMaxElement.push_back(idx);
            
            int N = idxMaxElement.size();
            if(N>=k){
                
                ans +=idxMaxElement[N-k]+1;
            }
        }//for
        
        
        return ans;
        
    }
};