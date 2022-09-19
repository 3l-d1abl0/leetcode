class Solution {
    
    struct Trie{
        
        Trie *child[2] = {NULL};
        
        /*Trie(){
            this->child[0] = NULL;
            this->child[1] = NULL;
        }*/
    };
    
    Trie *root;
    
    void insert(int num){
        
        Trie *node = root;
        
        for(int i=30; i>=0; i--){
            
            int bit = (num & (1<<i))>0?1:0;
            
            if(node->child[bit]== NULL)
                node->child[bit] = new Trie();
                
            node = node->child[bit];
        }
    }
    
    
    int find(int num){
        
        Trie *node = root;
        int ans =0;
        
        for(int i=30; i>=0; i--){
            
            int bit = (num & (1<<i))>0?1:0;
            
            
                if(node->child[!bit]!=NULL){
                    node = node->child[!bit];
                    ans |= (1<<i);
                }else
                    node = node->child[bit];
            
        }//for
        
        
        return ans;
    }
    
    
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        
        int N= nums.size();
        //1. sort the numbers
        sort(nums.begin(), nums.end());
        
        vector<pair<int, pair<int, int> >> Q;
        vector<int> ans(queries.size());
        
        int idx =0;
        for(auto ele: queries)
            Q.push_back({ele[1], {ele[0], idx++} });
        
        
        //2. Sort the queries
        sort(Q.begin(), Q.end());
        
        root = new Trie();
        
        int i=0;
        for(auto ele: Q){
            
            while(nums[i]<=ele.first && i<N){
                insert(nums[i]);
                i++;
            }
            
            if(i==0)
                ans[ele.second.second] = -1;        
            else
                ans[ele.second.second] = find(ele.second.first);
            
        }
        
        
        return ans;
    }
};