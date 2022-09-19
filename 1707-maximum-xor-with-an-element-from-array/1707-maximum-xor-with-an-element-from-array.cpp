class Solution {
    
    struct Trie{
        
        Trie *child[2];
        
        Trie(){
            this->child[0] = NULL;
            this->child[1] = NULL;
        }
    };
    
    Trie *root;
    
    void insert(int num){
        
        Trie *node = root;
        
        for(int i=30; i>=0; i--){
            
            //int bit = (num & (1<<i))>0?1:0;
            int bit = (num >> i) & 1;
            
            if(node->child[bit]== NULL)
                node->child[bit] = new Trie();
                
            node = node->child[bit];
        }
    }
    
    
    int find(int num){
        
        Trie *node = root;
        int ans =0;
        
        for(int i=30; i>=0; i--){
            
            //int bit = (num & (1<<i))>0?1:0;
            int bit = (num >> i) & 1;
            
                if(node->child[!bit]!=NULL){
                    node = node->child[!bit];
                    ans |= (1<<i);
                }else
                    node = node->child[bit];
            
        }//for
        
        
        return ans;
    }
    
    
public:
    
    vector<int> method2(vector<int>& nums, vector<vector<int>>& queries){
        const int n = nums.size(), q = queries.size();
        vector<int> ans(q, -1);
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < q; i++) {
            const int x = queries[i][0], m = queries[i][1];
            if (m < nums[0]) continue;
            
            int end = upper_bound(nums.begin(), nums.end(), m) - nums.begin();
            int start = 0;
            
            int k = 0, cur = 0;
            for (int bit = 31; bit >= 0; bit--) {
                if (x & (1 << bit)) { // hope A[i] this bit == 0
                    if (!(nums[start] & (1 << bit))) {
                        k |= 1 << bit;
                        end = lower_bound(nums.begin() + start, nums.begin() + end, cur | (1 << bit)) - nums.begin();
                    } else {
                        cur |= 1 << bit;
                    }
                } else { // hope: A[i] this bit == 1
                    if (start <= end - 1 && (nums[end - 1] & (1 << bit))) {
                        k |= 1 << bit;
                        cur |= 1 << bit;
                        start = lower_bound(nums.begin() + start, nums.begin() + end, cur) - nums.begin();
                    }
                }
            }
            ans[i] = k;
        }
        return ans;
    }
    
    
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        
        return method2(nums, queries);
        
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