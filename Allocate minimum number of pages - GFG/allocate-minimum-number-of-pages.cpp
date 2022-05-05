// { Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    
    bool func(int nums[], int N, int m, int maxSum){
        
        int subS = 1;
        int sum =0;
        for(int i=0; i<N; i++){
            
            int ele = nums[i];
            
            if(ele>maxSum) return false;
            
            if(sum+ele<=maxSum){
                sum +=ele;
            }else{
                subS++;
                if(subS > m) return false;
                sum = ele;
            }
        }
        return subS <= m;
        
    }
    
    //Function to find minimum number of pages.
    int findPages(int nums[], int N, int m) 
    {
        //code here
        
                
        int l = *max_element(nums, nums+N)-1;
        int r = accumulate(nums, nums+N, 0)+1;
        
        
        while(r-l>1){
        
            
            int mid = l+(r-l)/2;
            //predicate : mid <= max sum of a subset
            //int minMaxSum = ;
            if(func(nums, N, m, mid)==true){
                r=mid;  //try to go more left
               // cout<<"mid :: "<<mid<<endl;
            }else{
                l=mid;
            }
            
        }
        
        //cout<<":: "<<l<<" "<<r<<endl;
        
        return r;
        
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
  // } Driver Code Ends