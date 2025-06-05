class RandomizedSet {
    unordered_set<int> st;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(st.find(val)!= st.end()){
            return false;
        }else{
            st.insert(val);
            return true;
        }
    }
    
    bool remove(int val) {
        if(st.find(val)!= st.end()){
            st.erase(val);
            return true;
        }else{
            return false;
        }
    }
    
    int getRandom() {
        int lim = rand() % st.size();
        unordered_set<int>::iterator it=st.begin();
        int idx =0;
        for (it = st.begin(); idx <lim && it != st.end(); ++it) {
            idx++;
        }
        return *it;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */