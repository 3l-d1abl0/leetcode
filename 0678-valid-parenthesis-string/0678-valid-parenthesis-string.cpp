// Recursive Solution
class Solution {

    bool recur(int idx, int openingBracket, string &s, vector<vector<int>> &memo){
        /*
            //Going right to left
            ) - opens a potential match
            ( - closes a potential match

            When the brackets are balanced,
            there is no point processing ( (closing brackets)
            because it will always result in False
        */
        
        if(idx==-1)
            return (openingBracket==0);


        if(memo[idx][openingBracket]!=-1)
            return memo[idx][openingBracket];

        bool ans=false;

        if(s[idx]=='*'){
            
            ans|= recur(idx-1,openingBracket+1,s, memo); // Add ')'
            
            if(openingBracket)  //If the balance is 0 zero, no point bringting it to negative (
                ans|= recur(idx-1,openingBracket-1,s, memo); // Add ')'
            
            ans|= recur(idx-1,openingBracket,s, memo); //Add Nothing

        }else{

            if(s[idx]=='('){
                if(openingBracket)  //If the balance is 0 zero, no point bringting it to negative
                    ans= recur(idx-1,openingBracket-1,s, memo);
            }else{
                    ans= recur(idx-1,openingBracket+1,s, memo);
            }
        }

        memo[idx][openingBracket] = (ans==true)?1:0;
        return memo[idx][openingBracket];
    }

public:
    bool checkValidString(string s) {

        //1. Memoization  + recursion
        int N = s.size();
        vector<vector<int>> memo(N, vector<int>(N, -1));
        return recur(N-1,0,s, memo);
    }
};