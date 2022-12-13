//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    int maxDistinctNum(int a[], int n, int k)
    {
    	// Complete the function
    	
    	int i;
  multiset<int> s;
  // making multiset from given array
        for(i=0;i<n;i++){
            if(s.find(a[i])==s.end()||k==0)
            s.insert(a[i]);
            else
            {
                k--;
            }
        }
   
        if(k!=0)
        return s.size()-k;
        else{
            set<int> st;
            for(auto it:s){
                st.insert(it);
            }
            return st.size();
        }
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int n,i,k;
	cin>>n>>k;
	int arr[n];
	for(i=0;i<n;i++)
	cin>>arr[i];
	Solution ob;
	cout <<ob.maxDistinctNum(arr, n, k)<<"\n";
	  }
	return 0;
}

// } Driver Code Ends