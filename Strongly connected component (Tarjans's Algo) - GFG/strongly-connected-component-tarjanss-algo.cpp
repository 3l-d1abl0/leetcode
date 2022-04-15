// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution
{
	public:
    //Function to return a list of lists of integers denoting the members 
    //of strongly connected components in the given graph.
    vector<vector<int>> tarjans(int N, vector<int> adj[])
    {
        //code here
        
        vector<int> disc(N, -1);
        vector<int> low(N, -1);
        
        vector<bool> inStack(N, false);
        stack<int> st;
        
        
        vector<vector<int>> ans;
        
        int timer =-1;
        for(int i=0; i<N; i++){
            if(disc[i]==-1)
                DFS(i, timer, adj, disc, low, inStack, st, ans);
        }
        
        sort(ans.begin(), ans.end());
        
        return ans;
        
        
    }
    
    void DFS(int src, int &timer, vector<int> adj[], vector<int> &disc, vector<int> &low, vector<bool> &inStack, stack<int> &st, vector<vector<int>> &ans){

                timer ++;
                disc[src]=timer, low[src]=timer;
                
                
                st.push(src);
                inStack[src] = true;
                
                
                vector<int> res;
                
                for(int node: adj[src]){
                 
                    if(disc[node] == -1){   //unvisited , visit it
                        
                        DFS(node, timer, adj, disc, low, inStack, st, ans);
                        low[src] = min(low[src], low[node]);
                        
                    }else if(inStack[node]){ //check if its not a cross edge
                        
                        low[src] = min(low[src], disc[node]);
                        
                    }
                 
                    
                }
                
                
                if(low[src]==disc[src]){
                 
                 
                    while(!st.empty() && st.top()!= src){
                        inStack[st.top()] = false;
                        res.push_back(st.top());
                        st.pop();
                    }
                    
                    inStack[st.top()] = false;
                    res.push_back(st.top());
                    st.pop();
                    
                    //sorting the current components
                    sort(res.begin(), res.end());
                    ans.push_back(res);
                    
                    
                }
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
        vector<vector<int>> ptr = obj.tarjans(V, adj);

        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                if(j==ptr[i].size()-1)
                    cout<<ptr[i][j];
                else
                    cout<<ptr[i][j]<<" ";
            }
            cout<<',';
        }
        cout<<endl;
    }

    return 0;
}

  // } Driver Code Ends