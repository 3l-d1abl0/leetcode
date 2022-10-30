struct user{
    
    long long int total;
    string video_id;
    int views;
};

class Solution {
public:
    
    vector<vector<string>> mostPopularCreator(vector<string>& c, vector<string>& ids, vector<int>& v) {
     
        unordered_map<string, user> mp;
    
        int N = ids.size();
        long long int maxx = -100;
        
        for(int i=0; i<N; i++){
            
            if(mp.find(c[i])==mp.end()){
                
                mp[c[i]] = {v[i], ids[i], v[i]};
                maxx = max(maxx, 1LL*v[i]);
                
            }else{
                
                mp[c[i]].total += v[i];
                maxx = max(maxx, mp[c[i]].total);
                
                if(v[i] > mp[c[i]].views ){
                    mp[c[i]].views = v[i];
                    mp[c[i]].video_id = ids[i];
                }else if(v[i] == mp[c[i]].views ){
                    
                    if(ids[i].compare(mp[c[i]].video_id)  < 0)
                        mp[c[i]].video_id = ids[i];
                }
                
            }
        }//i
        
        vector<vector<string>> ans;
        for(auto ele: mp){
            
            if(ele.second.total == maxx){
                ans.push_back({ele.first, ele.second.video_id });
            }
        }
        
        
        return ans;
    }
};