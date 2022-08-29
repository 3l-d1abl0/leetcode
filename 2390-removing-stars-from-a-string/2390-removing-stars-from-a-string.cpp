class Solution {
public:
    string removeStars(string s) {
        
        
        string ans;
        
        int j=0;
        for(char ch: s){
            if(ch=='*'){
                if(!ans.empty())
                    ans.pop_back();
            }else
                ans+=ch;
        }
        
        return ans;
    }
};