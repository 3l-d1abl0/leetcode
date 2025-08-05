// Recursive Solution
class Solution {
    bool ex(int idx, int openingBracket, string &s, vector<vector<int>> &memo){
        
        
        if(idx==s.size())
            return (openingBracket==0);


        if(memo[idx][openingBracket]!=-1)
            return memo[idx][openingBracket];

        bool ans=false;
        if(s[idx]=='*'){
            
            ans|=ex(idx+1,openingBracket+1,s, memo); // Add '('
            
            if(openingBracket)  //If the balance is 0 zero, no point bringting it to negative
                ans|=ex(idx+1,openingBracket-1,s, memo); // Add ')'
            
            ans|=ex(idx+1,openingBracket,s, memo); //Add Nothing
        }else{
            if(s[idx]=='('){
                ans=ex(idx+1,openingBracket+1,s, memo);
            }else{

                if(openingBracket)  //If the balance is 0 zero, no point bringting it to negative
                    ans=ex(idx+1,openingBracket-1,s, memo);
            }
        }

        memo[idx][openingBracket] = (ans==true)?1:0;
        return memo[idx][openingBracket];
    }

public:
    bool checkValidString(string s) {

        int N = s.size();
        vector<vector<int>> memo(N, vector<int>(N, -1));
        
        return ex(0,0,s, memo);
    }
};