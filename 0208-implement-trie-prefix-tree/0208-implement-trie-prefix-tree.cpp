class Trie {
public:
    
    struct trie{
        bool isLeaf;
        map<char, trie*> children;
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
        
        for(int i=0; i<len; i++){
            
            auto it = temp->children.find(word[i]);
            if(it == temp->children.end()){
                temp->children[word[i]]= new trie();
            }
            
            temp = temp->children[word[i]];
        }
        
        temp->isLeaf = true;
    }
    
    bool search(string word) {
        
        int len = word.length();
        trie *temp = root;
        
        for(int i=0; i<len; i++){
            
            auto it = temp->children.find(word[i]);
            if(it == temp->children.end())
                return false;
            
            temp=temp->children[word[i]];
        }
        
        return temp->isLeaf;
    }
    
    bool startsWith(string prefix) {
     
        int len = prefix.length();
        trie *temp = root;
        
        for(int i=0; i<len; i++){
            
            auto it = temp->children.find(prefix[i]);
            if(it == temp->children.end())
                return false;
            
            temp=temp->children[prefix[i]];
        }
        
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */