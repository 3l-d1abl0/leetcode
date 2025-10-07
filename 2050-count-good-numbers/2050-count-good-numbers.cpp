class Solution {
public:
    
    int pow(long long num, long long x, int &MOD){
        
        if (x==0)
            return 1;
        
        num = num%MOD;
        
        int res = 1;
        
        while(x>0){
            
            if(x&1)
                res = (res*num)%MOD;
            
            x = x>>1;
            
            num = (num*num)%MOD;
            
        }//while
        
        //cout<<res<<endl;
        return res%MOD;
        
    }
    int countGoodNumbers(long long n) {
        /*
            even pos -> even numbers - 0 , 2, 4, 6, 8
            odd pos -> prime numbers - 2, 3, 5, 7
            
            5.4.5.4.5.4.5
        
        */
        
        int MOD = 1e9+7;
        long long int oddPos = n/2;
        long long int evenPos = n-oddPos;
        
        return (1LL * pow(5, evenPos, MOD) * pow(4, oddPos, MOD) )%MOD;
        
        //return ans%MOD;
    }
};