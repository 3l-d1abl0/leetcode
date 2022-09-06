class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        
        int ham =0;
        for(int idx=0; idx<32; idx++){
            
            int ctr=0;
            for(int ele: nums){
                
                ctr+= ele>>idx&1;
            }
            
            ham += ctr * (nums.size()-ctr);
        }//for
        
        return ham;
    }
};