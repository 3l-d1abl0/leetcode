class Solution {
public:
    
    bool palindrome(string s, int start, int end){
        
        while(start<=end){
            if(s[start++]!=s[end--])
                return false;
        }
        
        return true;
    }
    
    void solve(int idx, string s, vector<vector<string >> &ans, vector<string> &combList){
        
        
        if(idx == s.size()){
            ans.push_back(combList);
            return;    
        }   
        
        
        for(int i=idx; i<s.size(); i++){
        
            if(palindrome(s,idx, i)){
                combList.push_back(s.substr(idx, i - idx + 1));
                solve(i+1, s, ans, combList);
                combList.pop_back();
            }
            
        }

            
    }
    
    vector<vector<string>> partition(string s) {
        
        vector<vector<string>> ans;
        vector<string> combList;
        solve(0, s, ans, combList);
        
        return ans;
    }
};