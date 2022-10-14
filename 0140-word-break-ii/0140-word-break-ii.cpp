class Solution {
public:
    void solve(vector<string> &ans, int idx, string &s, string str, vector<string> &wd){

        if(idx==s.size()){
            if(str.size()!=0){
                str.pop_back();
                ans.push_back(str);
                return;
            }
        }
        
        

        for(int i=0; i<wd.size(); i++){

            int len = wd[i].size();

            if(wd[i].compare(s.substr(idx, len))==0){

                solve(ans,idx+len, s, str+wd[i]+" ", wd);
            }

        }//for

    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        
        vector<string> ans;
        solve(ans, 0, s, "", wordDict);
        
        return ans;
    }
};