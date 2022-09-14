class Solution {
public:
    
    void solve(unordered_set<string> &st, int idx , string s, string str, vector<string> &w){
        
        if(idx==s.size()){
            if(str.size()!=0){
                //ans.push_back(str);
                st.insert(str);
            }
        }
        
        for(int i=0; i<w.size(); i++){
            
            int len = w[i].size();
            if(s.size()==w[i].size())
                continue;
            
            if(w[i].compare(s.substr(idx, len))==0){
                solve(st, idx+len, s, str+w[i], w);
            }
        }
        
    }
    
    vector<string> method1(vector<string>& words){
        
        unordered_set<string> st;
        for(string ele: words)
            solve(st, 0, ele, "", words);
        
        vector<string> ans(st.begin(), st.end());
        return ans;
        
    }
    
    
    vector<string> method2(vector<string>& words) {
        
        vector<string> ans;
        unordered_set<string> dict(words.begin(), words.end());
        
        for(auto w : words) {
            
            if(w.empty()) continue;
            
            vector<int> dp(w.size() + 1, 0);
            dp[0] = 1;
            
            for(int st = 0 ; st<= w.size() ;  st++) {
                
                for(int ed = st+1 ; ed <= w.size() ; ed++) {
                    
                    if(ed-st >= w.size())
                        continue;
                    
                    if(ed-st < w.size() && dp[st] == 1 && dict.find(w.substr(st, ed-st)) != dict.end()) {
                        dp[ed] = 1;
                        //break;
                    }
                }
            }
            
            if(dp[w.size()])
                ans.push_back(w);
        }
        
        return ans;
        
    }
    
    
    bool solve(vector<int> &dp, int idx, string &str, vector<string> &words){
        
        if(idx == str.size())
            return true;
        
        if(dp[idx]!=-1)
            return dp[idx];
        
        
        for(int i=0; i<words.size(); i++){
            
            int len = words[i].size();
            if(words[i].compare(str.substr(idx, len))==0 && len!= str.size()){
                if(solve(dp, idx+len, str, words)){
                    
                    dp[idx]=1;
                    return true;
                }
            }
        }//for
        
        dp[idx] = false;
        return false;
        
    }
    vector<string> method3(vector<string>& words) {
        
        vector<int> dp(31, -1);
        vector<string> ans;
        for(string w: words){
            
            if(solve(dp, 0, w, words))
                ans.push_back(w);
            fill(dp.begin(), dp.end(), -1);
        }
        
        return ans;
    }
    
    
    vector<string> method4(vector<string> &words){
        Trie trie;
        for(string& word: words)
            trie.insert(word);
        
        vector<string> res;
        for(string& word: words){
            if(trie.search(word, 0, 0))
                res.push_back(word);
        }
        return res;
    }
    
    ////////
    struct Node {
    Node* links[26];
    bool end = false;
    
    bool containsKey(char ch){
        return links[ch-'a'] != NULL;
    }
    void put(char ch, Node* node){
        links[ch-'a'] = node;
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
};

class Trie {
public:
    Node* root;
    
    Trie(){
        root = new Node();
    }
    void insert(string& word){
        Node* node = root;
        for(char& ch: word){
            if(!node->containsKey(ch))
                node->put(ch, new Node());
            node = node->get(ch);
        }
        node->end = true;
    }
    bool search(string& word, int idx, int countWords){
        if(idx == word.size())
            return countWords >= 2;
        
        Node* node = root;
        for(int i=idx; i<word.size(); i++){
            char ch = word[i];
            if(!node->containsKey(ch))
                return false;
            
            node = node->get(ch);
            if(node->end)
                if(search(word, i+1, countWords+1))
                    return true;
        }
        return false;
    }
};
    ///////
    
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        
        //return method1(words);  //TLE
        
        //return method2(words);  //OK
        
        //return method3(words);//TLE
        
        
        return method4(words);
    }
        
};