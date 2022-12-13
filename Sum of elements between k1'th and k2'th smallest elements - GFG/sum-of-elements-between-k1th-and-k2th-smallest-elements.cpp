//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long sumBetweenTwoKth( long long A[], long long N, long long K1, long long K2)
    {
        // Your code goes here
        
        
        priority_queue<long long int > mxH;
        
        for(int i=0; i<N; i++){
            
            if(mxH.size() <K2-1){
                mxH.push(A[i]);
            }else if(A[i] < mxH.top()){
                mxH.pop();
                mxH.push(A[i]);
            }
        }
        
        long long int sum =0;
        int ctr =0;
        while(!mxH.empty() && ctr< (K2-K1-1) ){
            
            //cout<<mxH.top()<<" ";
            sum += mxH.top();
            mxH.pop();
            
            ctr++;
            
            //cout<<sum<<endl;
        }
        
        return sum;
    }
};

//{ Driver Code Starts.
int main()
 {
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        cin>>n;
        long long a[n+5];
        for(int i =0;i<n;i++)
            cin >> a[i];
        
        long long k1, k2;
        cin >> k1 >> k2;
        Solution ob;
        cout << ob.sumBetweenTwoKth(a, n, k1, k2) << endl;
        
    }
	return 0;
}

// } Driver Code Ends