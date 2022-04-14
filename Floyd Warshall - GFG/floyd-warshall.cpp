// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution {
  public:
	void shortest_distance(vector<vector<int>>&distance){
	    // Code here
	    int N = distance.size();
	    
	    	for(int k=0; k<N; k++){

		for(int i=0; i<N; i++){

			for(int j=0; j<N; j++){

				if(i==k || j==k || distance[i][k] == -1 || distance[k][j] == -1)	continue;
                
                
                
                if(distance[i][j]==-1)
                    distance[i][j] = distance[i][k] + distance[k][j];
                else{
                    
    				if(distance[i][j] > distance[i][k] + distance[k][j]){
    
    					distance[i][j] = distance[i][k] + distance[k][j];
    				}
				
                }

			}
		}
	}
	    
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution obj;
		obj.shortest_distance(matrix);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cout << matrix[i][j] << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends