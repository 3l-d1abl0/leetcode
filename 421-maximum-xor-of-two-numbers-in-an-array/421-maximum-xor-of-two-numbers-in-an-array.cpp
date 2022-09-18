class Solution {
public:
    int method1(vector<int> &nums){
        
        int maxx = 0;
        int N = nums.size();
        
        for(int i = 0; i < N- 1; i++){
            for(int j = i + 1; j < N; j++){
                maxx = max(maxx, nums[i] ^ nums[j]);
            }
        }
        return maxx;
        
    }
    
    
    struct Trie{
        
        Trie *child[2];
        
        Trie(){
            this->child[0] = NULL;
            this->child[1] = NULL;
        }
    };
    
    Trie *root;
    
    void insertTrie(int num){
        //30-0 (31)
        
        Trie *node = root;
        for(int i=30; i>=0; i--){
            
            int bit = ((1<<i)&num)>0?1:0;
            
            if(node->child[bit]==NULL)
                node->child[bit] = new Trie();
            
            node = node->child[bit];
        }
    }
    
    int findTrie(int num){
        //30-0 (31)
        
        Trie *node = root;
        int ans = 0;
        for(int i=30; i>=0; i--){
            
            int bit = ((1<<i)&num)>0?1:0;
            
            if(bit==0){
                
                //we want 1                
                if(node->child[!bit]!= NULL){
                    node = node->child[!bit];
                    ans |= (1<<i);  //set ith bit as 1
                }else{
                    ///1 doesn't exist so go for 0
                    node = node->child[bit];
                }
                
            }else{
                //we want 0
                if(node->child[!bit]!= NULL){
                    node = node->child[!bit];
                }else{
                    node = node->child[bit];
                    ans |= (1<<i);
                }
            }
        }//for
        
        return ans;
    }
    
    int method2(vector<int> &nums){
        
        root = new Trie();
        
        //Insert the numbers within Trie
        for(int ele: nums){
            insertTrie(ele);
        }
        
        //Find the best possible xored number for each number
        int maxx =0;
        for(int ele: nums){
            
            maxx = max(maxx, ele^findTrie(ele));
        }
        
        return maxx;
    }
    
    int findMaximumXOR(vector<int>& nums) {
        
        //Brute Force
        //return method1(nums);
        
        //Trie
        
        return method2(nums);
    }
};