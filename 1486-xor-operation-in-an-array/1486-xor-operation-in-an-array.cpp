class Solution {
public:
    
    int method1(int n, int start){
        
        int ans = 0;
        for(int i=0; i<n; i++){
            
            ans = (start+ (2*i))^ans;
        }
        
        return ans;
    }
    
    int method2(int n, int start){
        
        int last = start + 2*(n-1);
        
        if(start%4 <=1){
            
            if(n%4 ==0)
                return 0;
            else if(n%4==1)
                return last;
            else if(n%4==2)
                return 2;
                
            return last^2;  //==3
            
        }else{
            
            if(n%4 ==0)
                return last^start^2;
            else if(n%4==1)
                return start;
            else if(n%4==2)
                return last^start;
                
            return start^2;//==3
            
        }
    }
    
    int xorOperation(int n, int start) {
        
        
        //return method1(n, start);
        return method2(n, start);
    }
};