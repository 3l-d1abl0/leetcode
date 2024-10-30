class Solution {
public:
    
  struct Trie{

        const string* leaf;
        vector<Trie*> children;
        Trie(){
            children.resize(26, nullptr);
            leaf = nullptr;
        }
        ~Trie() noexcept {
            for( auto* node: children ) {
                delete node;
            }
        }
    };
    
    void dfs(Trie *node, vector<vector<char>> &board, int r, int c, vector<string> &ans){
        
        //out of bound
        if(r<0 || c<0 || r>=board.size() || c>= board[0].size() || board[r][c] == '\0')
            return;
        
        //If the character [r][c] does not exit in 
        if(node->children[board[r][c]-'a'] == nullptr)
            return;
        
        Trie *child = node->children[board[r][c]-'a'];
        
        //If a leaf node
        if(child->leaf != nullptr){
         
            ans.push_back( *(child->leaf) );
            child->leaf = nullptr;  //to avoid duplicate processing
            
        }
        
        //backup
        char tmp = board[r][c];
        board[r][c] = '\0';
        
        
        dfs(child, board, r+1, c, ans);
        dfs(child, board, r-1, c, ans);
        dfs(child, board, r, c+1, ans);
        dfs(child, board, r, c-1, ans);
        
        
        //restore
        board[r][c] = tmp;
        
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        
        int R = board.size();
        int C = board[0].size();
        unique_ptr<Trie> root( new Trie );
        
        for( const string &word: words ) {
            
            Trie *head = root.get();
            for(char ch: word){
                
                if( head->children[ch-'a'] == nullptr ) {
                    head->children[ch-'a'] = new Trie();
                }
                head = head->children[ch-'a'];   
            }
            
            head->leaf = &word; // store const ref ptr to the original word
        }
        
        
        vector<string> ans;
        
        for(int r=0; r<R; r++){
            for(int c=0; c<C; c++){
                //cout<<"looking: "<<board[r][c]<<endl;
                dfs(root.get(), board, r, c, ans);
            }
        }
        
        return ans;
    }
};