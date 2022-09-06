class Solution {
public:
    int hammingDistance(int x, int y) {
        
        
        int xy = x^y;
        return __builtin_popcount(xy);
        int ctr=0;
        while(xy>0){
            
            if(xy&1 ==1)
                ctr++;
            
            xy = xy>>1;
        }
        
        return ctr;
    }
};