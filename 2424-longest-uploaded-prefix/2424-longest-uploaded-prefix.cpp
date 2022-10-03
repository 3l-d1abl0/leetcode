class LUPrefix {
public:
    
    vector<int> range;
    int ptr;
    int len;
    LUPrefix(int n) {
        range = vector<int> (n+1, 0);
        len = n;
        ptr=0;
    }
    
    void upload(int video) {
        range[video] =1;
        
        while(ptr+1<=len && range[ptr+1]==1){
            ptr++;
        }
    }
    
    int longest() {
        return ptr;
    }
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */