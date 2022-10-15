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
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        
        vector<string> ans;
        method4(words, ans);
        
        return ans;
    }
};