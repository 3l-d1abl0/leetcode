class LFUCache {
public:
    int mxSize;
    int min_freq;
    
    struct Node{
        int key, value, fr;
    };
    
    unordered_map<int, list<Node> > fq_list;
    map<int, list<Node>::iterator > keyExists;
    
    LFUCache(int capacity) {
        mxSize = capacity;
        min_freq =0;
    }
    
    void update(list<Node>::iterator it){
    
        int k = (*it).key;
        int v = (*it).value;
        int f = (*it).fr;
        
        if(fq_list[f].size() == 1 && f == min_freq){
            min_freq++;
        }
        
        //erase from current list
        fq_list[f].erase(it);
        
        //place in front in the list above(fq+1)
        fq_list[f+1].push_front(Node{k, v, f+1});
       keyExists[k] = fq_list[f+1].begin();
        
    }
    
    int get(int key) {
        
        if(mxSize ==0 || keyExists.find(key) == keyExists.end())
            return -1;
        
        int val = (*keyExists[key]).value;
        
        //remove from current list and place in the list above one freq
        update(keyExists[key]);
        
        return val;
        
    }
    
    void put(int key, int value) {
        
        if(mxSize ==0) return;
        
        if(keyExists.find(key) == keyExists.end()){   // add new
            
            if(mxSize == keyExists.size()){
                //remove last from min freq
                int old_key = fq_list[min_freq].back().key;
                fq_list[min_freq].pop_back();
                keyExists.erase(old_key);
                
            }
            
            
            fq_list[0].push_front(Node{key, value, 0});
            keyExists[key] = fq_list[0].begin();
            
            min_freq =0;
            
            
        }else{ //update
            (*keyExists[key]).value = value;
        
            //remove from current list and place in the list above one freq
            update(keyExists[key]);
            
        }
        
        
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */