class Solution {
public:
    int averageValue(vector<int>& nums) {
        
        int ctr=0, sum=0;
        for(int ele: nums){
            
            if(ele%2==0 && ele%3==0){
                ctr++;
                sum+=ele;
            }
        }
        
        if(ctr==0)
            return 0;
        
        return sum/ctr;
    }
};