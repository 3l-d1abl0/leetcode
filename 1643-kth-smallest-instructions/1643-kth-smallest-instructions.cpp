class Solution {
public:
    
    string method1(vector<int>& destination, int k){
        
        int R= destination[0], C= destination[1];
        
        vector<vector<int>> dp(R+1, vector<int> (C+1, 0));
        
        for(int i=R; i>=0; i--){
            for(int j=C; j>=0; j--){
                
                if(i==R || j==C)
                    dp[i][j] =1;
                else
                    dp[i][j] = dp[i+1][j]+dp[i][j+1];
            }
        }
        
        string str;
        int i=0, j=0;
        
        while(i<R && j<C){
            
            if(k<=dp[i][j+1]){  //go right
                str.append("H");
                j++;
            }else{
                str.append("V");    
                k -= dp[i][j+1];
                i++;
            }
            
        }
        
        //cout<<str<<endl;
        
        
        for(;i<R; i++)
            str.append("V");
        for(;j<C;j++)
            str.append("H");
        
        
        
        return str;
    }
    
    
    unsigned long long nCr(int n, int r) {
        if (r > n) return 0;
        if (r == 0 || r == n) return 1;
        if (r > n - r) r = n - r; // Since C(n, r) == C(n, n-r)

        unsigned long long result = 1;
        for (int i = 1; i <= r; ++i) {
            result *= n - (r - i);
            result /= i;
        }
        return result;
    }
    
    string method2(vector<int>& destination, int k){
     
        int R = destination[0], C=destination[1];
        
        int N = R+C;
        
        string str;
        
        for(int i=0; i<N; i++){
            
            if(C!=0){   //can go H, but  check with k
                
                int ways = nCr( (R+C)-1, R);    //to go right
                
                if(k<=ways){
                    str.append("H");
                    C--;
                }else{
                    k-=ways;
                    str.append("V");
                    R--;
                }
                
                
            }else{
                str.append("V");
                R--;
            }
        }//for
        
        return str;
    }
    
    string kthSmallestPath(vector<int>& destination, int k) {
        
        //1. DP
        //return method1(destination, k);
        
        //2.Combination 
        return method2(destination, k);
        
    }
};