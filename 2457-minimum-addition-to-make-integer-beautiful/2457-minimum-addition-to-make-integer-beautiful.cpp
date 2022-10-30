class Solution {
public:
    
    bool checkDigSum(long long int n, int target){
        
        int sum =0;
        while(n){
            sum +=n%10;
            n/=10;
        }
        //cout<<"sum= "<<sum<<" "<<target<<endl;
        //cout<<(sum>target)<<endl;
        return sum <=target;
    }
    
    long long makeIntegerBeautiful(long long n, int target) {
     
        
        long long int x =0, ori = n;
        long long int base =10;
        
        while(!checkDigSum(n, target)){
            
            x += (base - (n%base));
            
            n = ori+x;
            //cout<<"n= "<<n<<endl;
            base *=10;
        }
        
        
        return x;
    }
};