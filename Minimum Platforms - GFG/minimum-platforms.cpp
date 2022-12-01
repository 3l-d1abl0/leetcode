//{ Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    
    int method1(int arr[], int dep[], int n){
        
        // Sort arrival and departure arrays
        sort(arr, arr + n);
        sort(dep, dep + n);
     
        // plat_needed indicates number of platforms
        // needed at a time
        int plat_needed = 1, result = 1;
        int i = 1, j = 0;
     
        // Similar to merge in merge sort to process
        // all events in sorted order
        while (i < n && j < n) {
            // If next event in sorted order is arrival,
            // increment count of platforms needed
            if (arr[i] <= dep[j]) {
                plat_needed++;
                i++;
            }
     
            // Else decrement count of platforms needed
            else if (arr[i] > dep[j]) {
                plat_needed--;
                j++;
            }
     
            // Update result if needed
            if (plat_needed > result)
                result = plat_needed;
        }
     
        return result;
        
    }
    
    
    int method2(int arr[], int dep[], int n){
        
        if(n==0)
            return 0;
            
            
            
        vector<pair<int, int> > interval(n);

    	for (int i = 0; i < n; i++) {
    		interval[i] = { arr[i], dep[i] };
    	}
            
        sort(interval.begin(), interval.end());
        
        
        int plat = 1;
        
        //min heap for ending time
        priority_queue<int, vector<int>, greater<int>> pq;
        
        pq.push(interval[0].second);
        
        for(int i=1; i<n; i++){
        
            /*looking for platform
             check if a meetign has ended
            */
            
            if(interval[i].first <= pq.top()) //new train arrives before existing train leaves
                plat++;
            else
                pq.pop();
            
            pq.push(interval[i].second);
            
        }
        
        
        return plat;
        
        
    }
    
    int findPlatform(int arr[], int dep[], int n){
    
        //sorting
        //return method1(arr, dep, n);
        
        //heap
        return method2(arr, dep, n);
            
        
    }
};


//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}
// } Driver Code Ends