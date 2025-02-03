class DisjointSet {
    int _size;
    vector<int> rank, parent, size; 
public: 
    DisjointSet(int n) {
        rank.resize(n+1, 0); 
        parent.resize(n+1);
        size.resize(n+1); 
        for(int i = 0;i<=n;i++) {
            parent[i] = i; 
            size[i] = 1; 
        }
        
        _size =n;
    }

    int findParent(int node) {
        if(node == parent[node])
            return node; 
        return parent[node] = findParent(parent[node]); 
    }

    void unionByRank(int u, int v) {
        int pu = findParent(u); 
        int pv = findParent(v); 
        
        if(pu != pv){
            
            if(rank[pu] < rank[pv]) {
                parent[pu] = pv; 
            }
            else if(rank[pv] < rank[pu]) {
                parent[pv] = pu; 
            }
            else {
                parent[pv] = pu; 
                rank[pu]++; 
            }
        }
    }

    void unionBySize(int u, int v) {
        int pu = findParent(u); 
        int pv = findParent(v); 
        
        if(pu != pv){
            
            if(size[pv] >= size[pu]) {
                parent[pu] = pv; 
                size[pv] += size[pu]; 
            }else{
                parent[pv] = pu;
                size[pu] += size[pv]; 
            }
            
        }
    }
    
    int componentSize(){
        int ctr=0;

        //If a parent has size ==1, it means that Row or colum is not utilized, (no stone on that row or column)
        for(int i=0; i<=_size; i++){
            if(parent[i]==i && size[i]>1)
                ctr++;
        }
        
        return ctr;
    }
};

void dfs(vector<vector<int>>& stones, int index, vector<bool>& visited) {
        visited[index] = true;
        
        int n = stones.size();
        for(int i = 0; i<n; i++) {
            if(!visited[i] &&
               ((stones[i][0] == stones[index][0]) || (stones[i][1] == stones[index][1]))) {
                dfs(stones, i, visited);
            }
        }
}

int method1(vector<vector<int>>& stones){

        int n = stones.size();
        vector<bool> visited(n, false);
        
        int count = 0;
        for(int i = 0; i<n; i++) {
            if(visited[i])
                continue;
            dfs(stones, i, visited);
            count++;
        }
        
        return n - count;
}
    

int method2(vector<vector<int>> &stones){
    
        int N = stones.size();
        int maxRow=-1, maxCol =-1;
        for(auto row: stones){
            maxRow = max(row[0], maxRow);
            maxCol = max(row[1], maxCol);
        }
        
        /*
        Treat each row/column as node

        2x3 grid
        R1 - node1
        R2 - node2
        C1 - node3
        C2 - node4
        C3 - node5
        */

        DisjointSet ds(maxCol+maxRow+1);
        
        for(auto row: stones){
            
            ds.unionBySize(row[0], maxRow+1+row[1]);
        }
        
        cout<<ds.componentSize()<<endl;
        return N-ds.componentSize();
    
}

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        
        /*
            For every component, every node can be removed except the lst Guy.
            So a component with n1 nodes n1-1 can be erased.

            for component 1: n1-1
            for component 2: n2-1
                           : n3-1
                           : n4-1
                           => N - #compnent
        */
        
        /*
            TC: O(n^2)
            SC: O(n) + O(n)stack

            70ms 
        */
        //return method1(stones); ///dfs
        
        /*
            TC: O(n⋅α(n)+maxRow+maxCol).
            SC: O(2n)

            11ms
        */
        return method2(stones); //union-find
        
    }
};