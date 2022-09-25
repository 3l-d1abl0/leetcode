class Solution {
public:
    
    static bool comp(pair<string, int> &p1, pair<string, int> &p2){
        if(p1.second==p2.second) return p1.first>p2.first;
        return p1.second>p2.second;
    }
    
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        
        int N = names.size();
        
//         vector<pair<string, int>> pp;
        
//         for(int i=0;i<names.size();i++)
//             pp.push_back({names[i], heights[i]});
        
        
        
//         sort(pp.begin(), pp.end(), comp);
        
//         vector<string> ans;
//         for(int i=0; i<N; i++) ans.push_back(pp[i].first);
        
        
        vector< pair<int, string> > pp;
        for(int i=0; i<N; i++){
            pp.push_back({ heights[i], names[i]});
        }
        
        sort(pp.rbegin(), pp.rend());
         vector<string> ans;
         for(int i=0; i<N; i++)
             ans.push_back(pp[i].second);
        
        
        
        
        return ans;
    
        
        
    }
};