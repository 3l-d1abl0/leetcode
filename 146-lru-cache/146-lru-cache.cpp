class LRUCache {
public:
    int size;
    list<pair<int, int>> ll;
    unordered_map<int, list<pair<int, int>>::iterator> mp;
    
    LRUCache(int capacity) {
        size = capacity;    
    }
    
    int get(int key) {
        
        if(mp.find(key)== mp.end()){
            return -1;
        }
        
        list<pair<int, int>>::iterator it;
        it = mp[key];
        int val = (*it).second;
        
        ll.erase(it);
        
        ll.push_front({key, val});
        mp[key] = ll.begin();
        
        return val;
    }
    
    void put(int key, int value) {
        
        if(mp.find(key)== mp.end()){
        
            if(mp.size()== size){
                int k = ll.back().first;
                mp.erase(k); //remove the last one from map
                ll.pop_back();  // remove the last one from back of the list
            }
            
            
        }else{
            ll.erase(mp[key]);
            //mp.erase(key);
        }
        
        ll.push_front({key, value});
        mp[key] = ll.begin();
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */