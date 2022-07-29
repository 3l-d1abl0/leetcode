class TreeAncestor {
//we create a dp array to store (2^i)th ancestor at index i of a node u
    int up[100000][20];
    
	//pre-computation to store (2^i)th ancestor of node at up[node][i]
	// Time : O(n logn)
    void dfs(vector<int> g[],int node,int par)
    {        
		//(2^0) = 1st ancestor of a node is its parent itself
        up[node][0] = par;
        
		/*
		for remaining we store (2 ^ i-1)th ancestor of (2^i-1)th ancestor of node 
		to calculate (2^i)th ancestor of the node
		*/
        for(int i=1;i<20;i++)
        {
            if(up[node][i-1] != -1)
                up[node][i] = up[ up[node][i-1] ][i-1];
        }
        
		//now we traverse to remaining childs and do the same
        for(auto &child : g[node])
        {
                dfs(g,child,node);
        }
    }
    
	//function to get kth ancestor in O(logn) time
    int getK(int node,int k)
    {
	//0th ancestor of a node is that node itself
        if(k == 0)
            return node;
	//1st ancestor is its parent
        if(k == 1)
            return up[node][0];
			
		//now we try to find the position of MSB in k
        int last = -1;
        for(int i=0;i<20;i++)
        {
            int bit = (k>>i)&1;
            if(bit)
                last = i;
        }
        
		//if there is no bit set or there doesn't exist (2^last)the ancestor we return -1
        if(last == -1 or up[node][last] == -1)
            return -1;
        
		//else we recur for the (2^last)th ancestor and unset this bit from k
        return getK(up[node][last],k ^ (1<<last));
    }
    
public:
    TreeAncestor(int n, vector<int>& parent) {
		//initializing the up array
        memset(up,-1,sizeof up);
        
		//constructing tree from parent array
        vector<int> g[n];
        for(int i=0;i<size(parent);i++)
        {
            if(i != 0)
                g[parent[i]].push_back(i);
        }
        
		//pre-computation
        dfs(g,0,-1);
    }
    
    int getKthAncestor(int node, int k) {
		//call the function, get the result
        int val = getK(node,k);
        return val;
    }
};