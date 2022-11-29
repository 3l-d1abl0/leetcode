//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

  

// } Driver Code Ends
// Function to find square root
// x: element to find square root
class Solution{
  public:
    long long int floorSqrt(long long int x) 
    {
        // Your code goes here   
        
        long long int l =-1, r= 1e7+1;
        
        while(r-l>1){
            
            long long int mid = l+(r-l)/2;
            
            if(mid*mid <= x)
                l= mid;
            else
                r=mid;
        }
        
        
        //cout<<l<<" "<<r<<endl;
        return l;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		Solution obj;
		cout << obj.floorSqrt(n) << endl;
	}
    return 0;   
}

// } Driver Code Ends