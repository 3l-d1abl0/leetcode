class Solution {
public:
    int fib(int n) {
        
        if(n==0)
            return 0;
        
        if(n==1) return 1;
        
        int f0= 0, f1 = 1;
        int curr;
        for(int i=2; i<=n; i++){
            
            curr = f0+f1;
            f0= f1;
            f1= curr;
            
            //cout<<"curr:: "<<curr<<endl;
        }
        
        
        return curr;
        
    }
};