class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
     
        
        map<int, int> mp;
        
        for(auto ele: items1){
            mp[ele[0]] += ele[1];
        }
        
        for(auto ele: items2){
            mp[ele[0]] += ele[1];
        }
        
        
        vector<vector<int>> ans;
        
        for(auto &[key, val]: mp){
            ans.push_back({key, val});
        }
        
        
        return ans;
        
    }
};