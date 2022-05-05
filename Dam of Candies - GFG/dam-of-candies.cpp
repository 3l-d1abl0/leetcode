// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{
    
    public:
    int maxCandy(int height[], int n) 
    { 
        // Your code goes here
                int l=0, r= n-1;
        
        int max_water=0;
        
        while(l<r){
            max_water = max(max_water, (r-l-1) * min(height[l], height[r]));
            //cout<<l<<" "<<r<<" "<<max_water<<endl;
            
            if(height[l]<height[r]){
                l++;
            }else if(height[l]> height[r]){
                r--;
            }else{
                l++;
                r--;
            }
            
        }
        
        return max_water;
    }   
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	int height[n];
    	for (int i = 0; i < n; ++i)
    	{
    		cin>>height[i];
    	}
    	
    	Solution obj;
    	
    	cout << obj.maxCandy(height,n)<<"\n";
    }
    return 0;
}  // } Driver Code Ends