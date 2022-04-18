class Solution {
public:
    
    bool isAdj(string a, string b){
        
        int len = a.size();
        int diff=0;
        for(int i=0; i<len; i++){
            
            if(a[i]!=b[i])  diff++;
            
        }
        
        if(diff==1) return true;
        
        
        return false;
        
        
    }
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        queue<tuple<string, int>> q;
        
        unordered_set<string> sset(wordList.begin(), wordList.end());
        
        q.push({beginWord, 1});
        
        //Remove the begin word if there in list
        if (sset.find(beginWord) != sset.end()) {
            sset.erase(beginWord);
        }
        
        vector<string> temp;
        while(!q.empty()){
            
            auto[word, hop] = q.front(); q.pop();
            //cout<<":: "<<word<<" "<<hop<<endl;
            
               for(auto it = sset.begin(); it != sset.end(); it++){
                    
                    if(isAdj(word, *it)){
                       
                        if(endWord.compare(*it) ==0)
                            return hop+1;
                        
                        
                        q.push({*it, hop+1});
                        
                        temp.push_back(*it);
                        
                    }
                }
            
                for(auto str: temp){
                    sset.erase(str);
                }
                temp.clear();
            
            
        }//whilke
        
        return 0;
        
    }
};