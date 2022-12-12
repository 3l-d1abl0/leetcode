class Solution {
public:
    
    vector<string> method1(vector<string> &words, int k){
        
        unordered_map<string, int> mp;
        
        for(string ele: words){
            mp[ele]++;
        }
        
        vector< pair<int, string> > node;
        for(auto &[str, f]: mp){
            node.push_back({f, str});
        }
        
        
        sort(node.begin(), node.end(), [&](pair<int, string> a, pair<int, string> b){
            return a.first == b.first ? a.second < b.second : a.first > b.first;
        });
        
        
        vector<string> ans;
        int ctr =0;
        for(auto it = node.begin(); it!= node.end() && ctr<k; it++, ctr++){
            ans.push_back( (*it).second);
        }
        
        
        return ans;
        
    }
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        
        
        //1. method2 - SORT - TC : O(NlogN)
        return method1(words, k);
    }
};