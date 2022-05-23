// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    int countFriendsPairings(int n) 
    { 
        // code here
        vector<long int> dp(n+1,0);
        dp[0]=1;  // null subset
        dp[1]=1;  // 1 way possible
        
        for(int i=2;i<=n;i++)
        {
            dp[i]=(dp[i-1] + (i-1)*dp[i-2])%1000000007;
        }
        return dp[n];
    }
};    
 

// { Driver Code Starts.
int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	Solution ob;
    	cout <<ob.countFriendsPairings(n); 
    	cout<<endl;
    }
} 
  // } Driver Code Ends