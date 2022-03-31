class Solution {
public:
    int climbStairs(int n) {
        
        if(n==1)    return 1;
        
        if(n==2)    return 2;
        
        int f1 = 1, f2=2;
        int curr;
        
        for(int i=3; i<=n; i++){
            
            curr = f1+f2;
            f1 = f2; f2 = curr;
        }
        
        return curr;
    }
};