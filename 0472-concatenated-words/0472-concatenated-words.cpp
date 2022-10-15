struct Node{
    
    Node *links[26];
    bool end=false;
    
};

class Trie{
    
    Node *root;
    
    public:
    
    Trie(){
        root = new Node();
    }
    
    void insert(string &wd){
        
        Node *temp = root;
        
        for(char ch : wd){
            
            if(temp->links[ch-'a'] == NULL)
                temp->links[ch-'a'] = new Node();
        
            temp = temp->links[ch-'a'];
        }
    
        temp->end = true;
        
    }


    bool search(string &wd, int idx, int hops){
        
        //end of string
        if(idx== wd.size()){
            return hops >1;
        }
        
        Node *tmp = root;
        
        for(int i= idx; i<wd.size(); i++){
         
            if(tmp->links[wd[i]-'a']== NULL)
                return false;
            
            tmp = tmp->links[wd[i]-'a'];
            
            if(tmp->end==true){
                if( search(wd, i+1, hops+1) )
                    return true;
            }
            
        }
        
        return false;
        
    }
    
};

class Solution {
public:
    
    void solve(unordered_set<string> &st, int idx , string s, string str, vector<string> &w){
        
        if(idx==s.size()){
            if(str.size()!=0){
                //ans.push_back(str);
                st.insert(str);
                return;
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
        
        vector<string> ans (st.begin(), st.end());
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
                    
                    if(dp[st] == 1 && dict.find(w.substr(st, ed-st)) != dict.end()) {
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
    
    
     void method4(vector<string> &words, vector<string> &ans){
        
        
        Trie *root = new Trie();
        //insert all words into Trie
        for(string wd : words)
            root->insert(wd);
        
        
        //find if any word had more than 2 end flag
        for(string wd : words){
            if(root->search(wd, 0, 0))  //word, index of word, hops
                ans.push_back(wd);
        }
        
        
    }
    
    
    ///////    
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        
        //return method1(words);  //TLE
        
        //return method2(words);  //OK
        
        //return method3(words);//TLE
        
        //Trie
        vector<string> ans;
        method4(words, ans);
        return ans;
    }
        
};