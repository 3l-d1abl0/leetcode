class Solution {
public:
    vector<int> partitionLabels(string s) {
        
        unordered_map<int, int> mp;
        
        for(int i=0; i<s.size(); i++)
           mp[s[i]] = i;
        
        int maxx =-1, prev =-1;
        vector<int> ans;
        for(int i=0; i<s.size(); i++){
            
            maxx = max(maxx, mp[s[i]]);
            if(i==maxx){
                ans.push_back(i-prev);
                prev =i;
            }
        }
        
        
        return ans;
    }
};