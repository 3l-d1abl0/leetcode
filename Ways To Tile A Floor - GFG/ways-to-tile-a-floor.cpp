// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
      long long dp[100001];
      int mod=1e9+7;
    long long numberOfWays(long long N) {
        //code here
        /*
        if(N<=1) return 1;
        
        if(dp[N]!=0) return dp[N];
        
        return dp[N] = (numberOfWays(N-1)+numberOfWays(N-2))%mod;
        */
        
        for(int i=0; i<=1; i++)
            dp[i] = 1;
            
        for(int i=2; i<=N; i++){
            dp[i] = (dp[i-1]+dp[i-2])%mod;
        }
        
        
        return dp[N];
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        
        cin>>N;

        Solution ob;
        cout << ob.numberOfWays(N) << endl;
    }
    return 0;
}  // } Driver Code Ends