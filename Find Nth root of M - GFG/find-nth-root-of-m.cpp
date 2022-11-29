//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	
	double multiply(double number, int n) {
    double ans = 1.0;
    for(int i = 1;i<=n;i++) {
        ans = ans * number;
    }
    return ans; 
}

void getNthRoot(int n, int m) {
    double low = 1;
    double high = m;
    double eps = 1e-7; 
    
    while((high - low) > eps) {
        double mid = (low + high) / 2.0; 
        if(multiply(mid, n) < m) {
            low = mid; 
        }
        else {
            high = mid; 
        }
    }
    
    cout <<n<<"th root of "<<m<<" is "<<low<<endl; 
    
}
	
	int NthRoot(int n, int m)
	{
	    
	    //getNthRoot(n, m);
	    // Code here.
	   long long int l =-1, r= 1e7+1;
        
        while(r-l>1){
            
            long long int mid = l+(r-l)/2;
            long long int ans =1;
            bool flag = false;
            for(int i=0; i<n; i++){
                ans *= mid;
                if(ans>m){
                    r=mid;
                    flag = true;
                    break;
                }
            }
            
            if(flag==true)
                continue;
                
            if(ans <= m)
                l= mid;
            else
                r=mid;
        }
        
        
        //cout<<l<<" "<<r<<endl;
        long long int ans =1;
        for(int i=0; i<n; i++)
            ans *=l;
            
        if(ans != m)
            return -1;
            
        return l;
	    
	    
	}  
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		Solution ob;
		int ans = ob.NthRoot(n, m);
		cout << ans << "\n";
	}  
	return 0;
}
// } Driver Code Ends