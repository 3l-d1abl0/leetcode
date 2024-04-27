class Solution {
public:
    
    
    int recursion(int num, int k, int N){
        
        if(N==0){
            
            //cout<<num<<" "<<k<<" "<<N<<endl;
            if(k>=2)
                return 1;
            else
                return 0;
        }
        
        if(num<=0)
            return 0;
        
        //exclude
        int ex = recursion(num-1, k, N);
        
        //include
        int in =0;
        if(num<=N)
            in = num*recursion(num, k+1, N-num);
        
        
        
        return max(in, ex);
        
    }
    
    int integerBreak(int n) {
        
        
        return recursion(n, 0, n);
    }
};