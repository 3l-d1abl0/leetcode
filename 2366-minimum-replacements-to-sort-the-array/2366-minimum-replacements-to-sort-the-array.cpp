class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        
        int N = nums.size();
        
        int prev = nums[N-1];
        long long total =0;
        for(int i=N-2; i>=0; i--){
            
            /*if(nums[i]<prev){
                prev = nums[i];
                continue;
            }*/
            
            int num = nums[i];
            
            int splits = ceil(1.0*num/prev);
            total += splits-1;
            
            prev = num/splits;
            
        }
        
        return total;
    }
};