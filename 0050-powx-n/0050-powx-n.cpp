class Solution {
public:
    
    double exponentModRecur(double A, long int B){
        // Base cases
        if (A == 0) return 0;
        if (B == 0)	return 1;


        double y = exponentModRecur(A, B/2);
        y = y * y;
        // If B is odd
        if(B&1)
            y = y * A;

        return y;
    }
    
    
    double method2(double A, long int B){

        /*
            x^11
            1 0 1 1
            x^8  x^4  x^2   x^1

            result = x^8 . x^2 . x^1 = x^11
        */

        if (A == 0) return 0; 

        if(B < 0) {
            B = B*-1L;
            A = 1 / A;
        } 
        
        //abs of long long
        //long num = labs(B);
        
        double res = 1;	 // Initialize result

        // Update x if it is more than or// equal to p
        //x = x % p; 

        // In case x is divisible by p;
        if (A == 0) return 0; 

        while (B > 0){
            
            // If y is odd, multiply x with result
            if (B & 1)
                res = (res*A);// % p;

            // half the y
            B = B>>1; 
            A = (A*A);// % p;
        }

        return res;
    }


    double method1(double x, int n){

        long N;
        if(n < 0) {    
            N = n*-1L;
             return 1/exponentModRecur(x, N);
        } 
        
        return exponentModRecur(x, n);

    }
    
    double myPow(double x, int n) {

        /*
            x^(-n)
            1/(x^n) = (1/x)^n
        */

        //1. Recursive
        //return method1(x, n);


        //2. Iterative
        return method2(x, n);


        

        
        //abs of long long
//         long num = labs(n);
        
//         double pow = 1;
        
//         while(num){ // equivalent to while(num != 0)
//             if(num & 1) { // equivalent to if((num & 1) != 0)
//                 pow *= x;
//             }
            
//             x *= x;
//             num >>= 1;
//         }
        
//         return pow;
    }
};