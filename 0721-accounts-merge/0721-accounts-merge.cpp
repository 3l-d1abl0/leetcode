class DisjointSet {
    vector<int> rank, parent, size; 
public: 
    DisjointSet(int n) {
        rank.resize(n+1, 0); 
        parent.resize(n+1);
        size.resize(n+1); 
        for(int i = 0;i<n;i++) {
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
    
    int totalComponent(){
        int N = parent.size();
        int cnt=0;
        for(int i=0; i<N;i++)
            if(parent[i]==i){
                cout<<i<<" => "<<parent[i]<<endl;
                cnt++;
            }
        
        
        return cnt;
    }
};


class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        
        
        int N = accounts.size();
        
        //Mapping of email -> account-id
        unordered_map<string, int> mp;
        
        DisjointSet ds(N);//there can be N components
        
        /*
            For every email,
            map it to account-id or parent-account-id
        */
        
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
        
        
        /*
            parents-child connection has been formed
            Each emails maps to it account-id or parent-accoutn-id
        */
        
        vector<vector<string>> ans;
        //patent_id - to idx in the ans vecrtor
        unordered_map<int, int> parToAns;
        for(auto row: mp){
            
            //get the parent account id for the accound_id
            int parent_account_id = ds.findParent(row.second);
            
            //if parent account id does not exist in ans vector, add new
            if(parToAns.find(parent_account_id) == parToAns.end()){
                ans.push_back({accounts[parent_account_id][0], row.first}); ///{name, email}
                parToAns[parent_account_id] = ans.size() -1; //<parent_id, ans_row>
            }else{
                //parent_id exists in and
                int ans_idx = parToAns[parent_account_id];
                ans[ans_idx].push_back(row.first);//push the email
            }
        }
        
        //sort the emails
        for(auto& row: ans){
            sort(row.begin()+1, row.end());
        }
        //ElogE


        
        return ans;
        /*
        Time Complexity: O(E⋅α(N)+ElogE)
        Space Complexity: O(E+N)
        */
    }
};