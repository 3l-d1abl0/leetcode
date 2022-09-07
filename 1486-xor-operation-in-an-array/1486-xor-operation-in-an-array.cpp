class Solution {
public:
    
    int method1(int n, int start){
        
        int ans = 0;
        for(int i=0; i<n; i++){
            
            ans = (start+ (2*i))^ans;
        }
        
        return ans;
    }
    
    int xorOperation(int n, int start) {
        
        
        return method1(n, start);
    }
};