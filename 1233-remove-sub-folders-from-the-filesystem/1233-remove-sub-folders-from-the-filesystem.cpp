class Trie {
public:
    
    struct trie{
        bool isLeaf;
        map<string, trie*> children;
        trie(){
            isLeaf = false;
        }
    };
    
    trie *root = NULL;
        
    Trie() {
        root = new trie();
    }
    
    void insert(string word) {
        int len = word.length();
        
        trie *temp = root;
        
        stringstream ss(word);
        string token;
        
        //for(int i=0; i<len; i++){
        while (!ss.eof()) {
            getline(ss, token, '/');
            
            if(token.empty())
                continue;
            
            //cout<<"__"<<token.length()<<"__"<<endl;
            
            //if character is in children map
            auto it = temp->children.find(token);
            if(it == temp->children.end()){
                temp->children[token]= new trie();
            }
            
            temp = temp->children[token];
            
        }
        
        temp->isLeaf = true;
    }
    
    void dfs(string &word, vector<string> &ans, trie *node){
        
        if(node->isLeaf){
            //cout<<"wd: "<<word<<endl;
            ans.push_back(word);
            return;
        }else{
            
            
            for(auto [ch, child]: node->children){
                word+='/';
                word+=ch;
                //cout<<ch<<" "<<word<<endl;
                dfs(word, ans, child);
        
                for(int i=0; i<(int)ch.size(); i++){
                    word.pop_back();    
                }
                //cout<<"word: "<<word<<endl;
                word.pop_back();
            }
        }
        
        //cout<<"-----"<<endl;
    }
    
    vector<string> search(){
        
        vector<string> ans;
        string word="";
        
        trie *temp = root;
        dfs(word, ans, temp);
        return ans;
    }
    
    
};



class Solution {
public:
    
    vector<string> method1(vector<string>& folder){
        
        //sort alphabetical
        //sort(folder.begin(),folder.end());
        
        //find the root folders        
        vector<string> rootStore;
        rootStore.push_back(folder[0]);
        
        for(int i=1;i<folder.size();i++){
            
            string root=rootStore.back();
            
            //If it doesn't start with the current roor, its a new Root
            if(folder[i].substr(0,root.size())!=root){
                
                    rootStore.push_back(folder[i]);
            }else{
                if(folder[i][root.size()]!='/')
                    rootStore.push_back(folder[i]);
            }
        }
 
        return rootStore;
    }
    
    
    vector<string> method2(vector<string>& folder){
        
        Trie* obj = new Trie();
        
        for (string name: folder){
            obj->insert(name);
        }
        
        
        return obj->search();
    }
    
    vector<string> removeSubfolders(vector<string>& folder) {
        
        //1. return method1
        //return method1(folder);
        
        //2 Method2  - Trie
        return method2(folder);
        

        
        
    }
};