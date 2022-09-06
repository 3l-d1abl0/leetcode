class Solution {
public:
    
    int method1(vector<int> &A){
        
        int N = 1 << 16;
        vector<int> dp(N, 0);
        
        dp[N - 1] = 1;
        for (int i = 0; i < 3; i++) {
            
            vector<int> temp(N, 0);
            for (int k = 0; k < N; k++) {
                for (int a : A) {
                    temp[k & a] += dp[k];
                }
            }
            dp = temp;
        }
        return dp[0];
        
    }
    
    
    
    int method2(vector<int> &A){
        
        int i, j;
        int N = A.size();
        int Result = 0;
        
        vector<int> Map(1 << 16);
        
        for(i = 0; i < N; i++)
        {
            for(j = 0; j < N; j++)
            {
                Map[(A[i] & A[j])]++;
            }
        }
        
        for(i = 0; i < N; i++)
        {
            for(j = 0; j < (1 << 16); j++)
            {
                if((A[i] & j) == 0)
                {
                    Result += Map[j];
                }
                else
                {
                    j += (A[i] & j) - 1;
                }
            }
        }
        
        return Result;
    
    }
    
    int method3(vector<int>& a) {
        int n = a.size();
        vector<int> b(1 << 16); 
        for(auto x : a) b[x]++;
        fwht(b, false);
        for(auto& x : b) x = x * x * x;
        fwht(b, true);
        return b[0];
    }
    
    void fwht(vector<int>& a, bool inv) {
        int n = a.size();
        for(int m = 1; 2 * m <= n; m *= 2) {
            for(int i = 0; i < n; i += 2 * m) {
                for(int j = 0; j < m; ++j) {
                    auto x = a[i + j];
                    auto y = a[i + j + m];
                    if(not inv) {
                        a[i + j] = y;
                        a[i + j + m] = x + y;
                    } else {                        
                        a[i + j] = -x + y;
                        a[i + j + m] = x;
                    }
                }
            }
        }
    }
    
    
    int method4(vector<int>& A) {
        
        std::array<int, 65536> m{};
        int ans = 0;
        
        for (int a : A)
            for (int b : A)
                m[a & b]++;
        
        for (int a : A) {
            for (int j = 0; j < 65536; j++) {
                if (const int k = a & j; !k)
                    ans += m[j];
                else
                    j += k - 1;
            }
        }
        
        return ans;
    }
    
    int countTriplets(vector<int>& nums) {
        
        
        //return method1(nums); //TLE
        //return method2(nums);   //140ms
        //return method3(nums);   //546ms
        return method4(nums);
        
        unordered_map<int, int> mp;
        
        for(int ele: nums){
            
            for(int a: nums)
                mp[ele&a]++;
        }
        
        
            for( auto &[key, value]: mp )
                cout<<key<<" "<<value<<endl;
        
        int ctr=0;
        for(int ele: nums){
            
            for( auto &[key, value]: mp ){
                if( (key & ele)==0 )
                    ctr+=value;
            }
        }
        
        return ctr;
        
    }
};