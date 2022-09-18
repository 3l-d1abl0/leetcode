class Solution {
public:
    
    vector<int> method1(vector<string>& words) {
        
        
        unordered_map<string, int> mp;
        
        for(string ele: words){
            
            string str="";
            
            for(char ch:ele){
                str+=ch;
                mp[str]++;
            }
        }
        
        vector<int> ans;
        for(string ele: words){
            
            string str="";
            int sum =0;
            for(char ch:ele){
                str+=ch;
                sum += mp[str];
            }
            ans.push_back(sum);
        }
        
        
        return ans;

        
        
    }
    
    
    struct Trie{
        char ch;
        int prefix;
        Trie* children[26] = {NULL};
        
    };
    
    Trie *root = new Trie();
    
    void insert(string word) {
            Trie *ptr = root;
        
            for(char ch : word){
                if(ptr->children[ch-'a'] == NULL)
                    ptr->children[ch-'a'] = new Trie();
                
                ptr = ptr->children[ch-'a'];
                ptr->prefix++;
            }
    }
    
    int countPrefix(string word) {
        Trie* ptr = root;
    
        int ctr = 0;
        for(char ch : word) {
            
            if(ptr->children[ch - 'a'] == NULL)
                break;
            ptr = ptr->children[ch - 'a'];
            ctr += ptr->prefix;
        }
        return ctr;
    }
    
    
    
    
    vector<int> method2(vector<string>& words) {
        
        for(string ele: words) insert(ele);
        
        vector<int> ans;
        for(string ele:words){
            ans.push_back(countPrefix(ele));
        }
        
        return ans;
        
    }
    
    
    const uint64_t MOD = 184467440737091;
    
    vector<int> method3(vector<string>& words) {
        
        unordered_map<uint64_t, int> prefixscore;
        for (auto word : words)
        {
            uint64_t hash = 0;
            for (auto c : word)
            {
                hash = (131313 * hash + (c - 96)) % MOD;
                ++prefixscore[hash];
            }
        }
        vector<int> answer;
        for (auto word : words)
        {
            uint64_t hash = 0;
            int ans = 0;
            for (auto c : word)
            {
                hash = (131313 * hash + (c - 96)) % MOD;
                ans += prefixscore[hash];
            }
            answer.push_back(ans);
        }

        return answer;
    }
    
    vector<int> sumPrefixScores(vector<string>& words) {
        
        //return method1(words);    
        
        //return method2(words);
        
        return method3(words);
    }
};