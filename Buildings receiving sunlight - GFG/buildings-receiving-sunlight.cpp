//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    int longest(int arr[],int n)
    {
        // Write your code here
        
        stack<int> st;
        
        for(int i=n-1; i>=0; i--){
            
            
            if(st.empty())
                st.push(arr[i]);
            else{
                
                
                while(!st.empty() && arr[i]>st.top())
                    st.pop();
                    
                st.push(arr[i]);
            }
        }//for
        
        
        return st.size();
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int i, arr[n+5];
        for(i=0;i<n;i++)
        cin>>arr[i];
        Solution ob;
        cout<<ob.longest( arr, n )<<endl;
    }
    return 0;
}
// } Driver Code Ends