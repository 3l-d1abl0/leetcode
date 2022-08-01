/*
 * @lc app=leetcode id=1483 lang=cpp
 *
 * [1483] Kth Ancestor of a Tree Node
 */

// @lc code=start
class TreeAncestor
{
public:
    vector<vector<int>> up;
    vector<int> depth;
    int LOG;
    
    vector<vector<int>> createGraph(int n, vector<int> &parent){
        
        //vector<int> g[n];
        vector<vector<int>> g(n);
        
        for(int ele=0; ele< parent.size(); ele++){
            
            if(parent[ele]!=-1){
                g[parent[ele]].push_back(ele);
            }
        }
        
        return g;
    }
    
    void precompute(vector<vector<int>> &graph, int node, int parent){
        

        up[node][0] = parent;

        for (int i = 1; i < LOG; i++){

            if (up[node][i - 1] != -1)
                up[node][i] = up[up[node][i - 1]][i - 1];
            else
                up[node][i] = -1;
        }
        
        
        for(int child: graph[node]){
            precompute(graph, child, node);    
        }
        
    }
    
    TreeAncestor(int n, vector<int> &parent){
        
        vector<vector<int>> graph = createGraph(n, parent);
        
        LOG = abs(log2(n))+1;

        up = vector<vector<int>>(n, vector<int>(LOG));
        
        
        //pre-computation
        precompute(graph, 0, -1);
        
        /*
        for(auto row: up){
            for(auto ele: row){
                cout<<ele<<" ";
            }
            
            cout<<endl;
        }*/

    }

    int getKthAncestor(int node, int k){
        
        //if(k==1) return up[node][0];

       //cout<<"K::"<<ceil(log2(k))+1<<endl;;
        int j;
        for(j = ceil(log2(k))+1; j >= 0; j--) {
            
            if(k >= (1 << j)) {
                //cout<<node<<" "<<j<<"--"<<k<<endl;
                node = up[node][j];
                if(node ==-1)   return node;
                k -= 1 << j;
                //cout<<node<<" "<<j<<" "<<k<<endl;
                //cout<<k<<" "<<(1<<j)<<endl;
            }
        }//for
        
        //cout<<"k ="<<k<<" j="<<j<<endl<<endl;
        //if(j==-1) return j;else 
        if(k==0)
            return node;
        else
            return j;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */
// @lc code=end
