class Solution {
public:
    
    int lessThanEq(int m, int n, int num){
        
        
        int sum =0;
        for(int i=1; i<=m; i++){
            
            //cout<<l<<"  "<<r<<endl;
            sum += min(num/i, n);
        }
        
        return sum;
    }
    
    int findKthNumber(int m, int n, int k) {
        
        int l=0, r= m*n;
        
        while(r-l>1){
            
            int mid = l +(r-l)/2;
            
            if(lessThanEq(m, n, mid) >=k){
                r=mid;
            }else{
                l=mid;
            }
        }
        
        cout<<l<<" "<<r<<endl;
        return r;
    }
};