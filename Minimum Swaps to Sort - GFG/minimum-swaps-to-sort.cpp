//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    // Code here
	    int N = nums.size();
	    vector<int> pos(nums);
	    sort(pos.begin(), pos.end());
	    
	    unordered_map<int, int> mp;
	    for(int i=0; i<N; i++){
	        mp[pos[i]] = i;
	    }
	    
	    int cnt =0;
	    
	    while(1){
	        
	        bool flag = false;
	        
	        for(int i=0; i<N; i++){
	            
	            if(mp[nums[i]]==i)
	                continue;
	                
	            flag = true;
	            cnt++;
	            
	            int pos = mp[nums[i]];
	            swap(nums[i], nums[pos]);
	        }
	        
	        if(flag == false)
	            return cnt;
	        
	    }//while
	    
	    return cnt;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends