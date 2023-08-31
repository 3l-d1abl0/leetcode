class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        
        unordered_map<string, vector<string> > mp;
        
        for(string s : strs){
            
            string sorted = s;
            sort(sorted.begin(), sorted.end());
            mp[sorted].push_back(s);
        }
        
        
        vector<vector<string>> ans;
            
        for(auto pp: mp){
            ans.push_back(pp.second);
        }
        
        
        return ans;
    }
};