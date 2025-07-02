class Solution {
public:
    struct Trie {
        Trie *child[26];
        int index;
        Trie()
        {
            for(int i=0;i<26;i++)
               child[i]=NULL; 
            index=-1; // Not assigned
        }
    };
    Trie *root;
    void insert(int start,int index, string &s)
    {
        Trie *t=root;
        for(int i=start;i<s.size();i++)
        {
            if(t->child[s[i]-'a']==NULL)
                t->child[s[i]-'a']=new Trie();
            t=t->child[s[i]-'a'];
            if(t->index==-1 || t->index==index)
                t->index=index;   
            else
                t->index=-2;   // Belongs to multiple strings 
        }
    }
    vector<string>res;
    bool compare(string &a, string &b)
    {
        if(b=="")
           return true;
        if(a.size()!=b.size())
           return a.size()<b.size();
        return a<b;      
    }
    void dfs(Trie *node, string curr)
    {
        if(node==NULL)
           return;
        if(node->index>=0 && compare(curr, res[node->index]))
            res[node->index]=curr;
        for(char i='a';i<='z';i++)
            dfs(node->child[i-'a'],curr+i);
    }
    vector<string> shortestSubstrings(vector<string>& arr) 
    {
        root=new Trie();
        int n=arr.size();
        res.resize(n,"");
        for(int index=0;index<n;index++)
        {
            for(int i=0;i<arr[index].size();i++)
               insert(i, index, arr[index]);
        }
        dfs(root,"");
        return res;
    }
};