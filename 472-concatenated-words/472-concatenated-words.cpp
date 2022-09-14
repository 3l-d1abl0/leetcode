class Solution {
public:
    
    void solve(unordered_set<string> &st, int idx , string s, string str, vector<string> &w){
        
        if(idx==s.size()){
            if(str.size()!=0){
                //ans.push_back(str);
                st.insert(str);
            }
        }
        
        for(int i=0; i<w.size(); i++){
            
            int len = w[i].size();
            if(s.size()==w[i].size())
                continue;
            
            if(w[i].compare(s.substr(idx, len))==0){
                solve(st, idx+len, s, str+w[i], w);
            }
        }
        
    }
    
    vector<string> method1(vector<string>& words){
        
        unordered_set<string> st;
        for(string ele: words)
            solve(st, 0, ele, "", words);
        
        vector<string> ans(st.begin(), st.end());
        return ans;
        
    }
    
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        
        //return method1(words);
        
        vector<string> res;
        unordered_set<string> dict(words.begin(), words.end());
        for(auto w : words) {
            if(w.empty())
                continue;
            vector<int> dp(w.size() + 1, 0);
            dp[0] = 1;
            for(int i = 1 ; i <= w.size() ;  i++) {
                for(int j = 0 ; j < i ; j++) {
                    if(i - j < w.size() && dp[j] == 1 && dict.find(w.substr(j, i - j)) != dict.end()) {
                        dp[i] = 1;
                        break;
                    }
                }
            }
            if(dp[w.size()])
                res.push_back(w);
        }
        return res;
        
    }
};