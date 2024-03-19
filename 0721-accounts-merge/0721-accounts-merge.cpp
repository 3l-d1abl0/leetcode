class DisjointSet {
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
};


class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        
        
        int N = accounts.size();
        
        
        unordered_map<string, int> mp;
        
        DisjointSet ds(N);
        
        int account_idx =0;
        for(auto row: accounts){
            
            for(int i=1; i<row.size(); i++){
                
                string email = row[i];
                
                //IF email doesnt exit , create a mapping
                if(mp.find(email)==mp.end()){
                    mp.insert( {email, account_idx} );
                }else{
                    //If email exists join the twoo accounts
                    ds.unionByRank(account_idx, mp[email]);
                }
                
            }
            
            account_idx++;
        }//for
        
        
        //form list - gather all emails of a parent
        vector<vector<string>> ls(N, vector<string>());
        
        for(auto row: accounts){
            
            //find parent account
            int parent = ds.findParent(mp[row[1]]);
            
            //push all emails to parent account
            for(int i=1; i<row.size(); i++)
                ls[parent].push_back(row[i]);
                
        }//for
        
        
        //form answer
        int idx=0;        
        vector<vector<string>> ans;
        for(auto row: ls){
            
            if(row.size()!=0){
                
                set<string> st(row.begin(), row.end());
                
                vector<string> tmp;
                tmp.push_back(accounts[idx][0]);
                for(auto ele: st){
                    tmp.push_back(ele);
                }
                
                ans.push_back(tmp);
            }
            
            idx++;
        }
        
        return ans;
    }
};