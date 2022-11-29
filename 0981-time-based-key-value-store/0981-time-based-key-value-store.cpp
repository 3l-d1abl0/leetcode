struct Node{
    string val;
    int stamp;
};

class TimeMap {
public:
    
    unordered_map<string, vector<Node>> mp;
    
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        if(mp[key].size()==0)
            return "";
        
        int l=-1, r=mp[key].size();
        while(r-l>1){
            int mid = l+(r-l)/2;
            
            if(mp[key][mid].stamp<=timestamp)
                l=mid;
            else
                r=mid;
        }
        
        //cout<<l<<" "<<r<<endl;
        if(l==-1)
            return "";
        //cout<<mp[key][l].val<<" "<<mp[key][l].stamp<<" --";
        //cout<<mp[key][r].val<<" "<<mp[key][r].stamp<<endl<<endl;
        return mp[key][l].val;
    }
};
/*

foo-> [bar, 1] [bar2 4]

*/


/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */