class Solution {
public:
    
    int posRightBit(int n){
        
        if(n==0)
            return -1;
        
        int idx =0;
        //while(n>=(1<<idx)){
        while(true){
            //cout<<(n & (1<<idx))<<" "<<(1<<idx)<<endl;
            if( (n & (1<<idx)) == (1<<idx))
                return idx;
            idx++;
        }
        
        return -1;
    }
    vector<int> singleNumber(vector<int>& nums) {
        
        
        if(nums.size()==2)
            return nums;
        int xy = 0;
        for(int ele: nums){
            xy ^= ele;
        }
        
        //cout<<xy<<" "<<posRightBit(xy)<<endl;
        
        int idx = posRightBit(xy);
        int xored =0;
        for(int ele: nums){
            if((ele & (1<<idx)) == (1<<idx))
                xored ^= ele;
        }
     
        
        return {xored, xored^xy};
    }
};