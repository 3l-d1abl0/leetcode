//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	

    int rotatedBS(int arr[], int l, int r){
        
        while(arr[l]>arr[r]){
            
            int mid = l+(r-l)/2;
            
            if(arr[mid]<=arr[r]){
                r =mid;
            }else{
                l=mid+1;
            }
            
        }
        
        
        return l;
        
    }

	int findKRotation(int arr[], int n) {
	    // code here
	    
	    
	    return rotatedBS(arr, 0, n-1);
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findKRotation(a, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends