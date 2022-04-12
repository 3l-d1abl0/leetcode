// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	
void dfs(int i, vector<int> adj[], stack<int> &st, vector<bool> &visited){

	visited[i]=true;

	for(int node: adj[i]){
		if(visited[node]==false)
		dfs(node, adj, st, visited);
	}

	st.push(i);

}

    void revDFS(int src, vector<vector<int>> &tran, vector<bool> &visited){
    
    	visited[src]=true;
    	//cout<<src<<" ";
    	for(int node: tran[src]){
    		if(visited[node]==false)
    			revDFS(node, tran, visited);
    	}
    
    }
	
    int kosaraju(int N, vector<int> adj[])
    {
        //code here
        	//1. Do a DFS and store it in stack
    	stack<int> st;
    	vector<bool> visited(N, false);
    
    	for(int i=0; i<N; i++){
    
    		if(visited[i]==false)
    		dfs(i, adj, st, visited);
    
    	}
        
        
        //2. reverse the adj
    	vector<vector<int>> tran(N);
    
    	for(int i=0; i<N; i++){
    		visited[i]=false;
    		for(int ele: adj[i]){
    			tran[ele].push_back(i);
    		}
    	}
    
    
    	//3. pick up ele from
        int ctr=0;
    	while(!st.empty()){
    
    		int src = st.top(); st.pop();
    
    		if(visited[src]==false){
    
    			revDFS(src, tran, visited);
    			//cout<<endl;
    			ctr++;
    		}
    	}
    	
    	
    	return ctr;
        
    }
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends