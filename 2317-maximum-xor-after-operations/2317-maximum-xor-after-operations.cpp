class Solution {
public:
    int method1(vector<int>& nums){
        
        int ans =0;
        for(int ele: nums){
            ans |= ele;
        }
        
        return ans;
        
    }
    
    
    int method2(vector<int> &nums){
        
        int ans =0;
        for(int i=30; i>=0; i--){
            
            for(int ele: nums){
                if(ele&(1<<i)){
                    ans |= (1<<i);
                    break;
                }
            
            }//for
        }//for
        
        return ans;
        
    }
    
    int maximumXOR(vector<int>& nums) {
        
        
        //return method1(nums);
        return method2(nums);
    }
};