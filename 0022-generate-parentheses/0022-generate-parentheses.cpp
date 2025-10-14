class Solution {
public:
    /*
        op - remaining opening Bracket
        cl - remaining closing bracket
    
    */
    void genParenth(int op, int cl, string str, vector<string> &ans){
        
        //no more bractes Left
        if(op==0 && cl==0){
            ans.push_back(str);
            return;
        }
        //have some opening brackets
        if(op>0){
            str.push_back('(');
            genParenth(op-1, cl, str, ans);
            str.pop_back();
        }
        //remaining opening bracket is less than remaining closing bracket
        //if you have more closing brackets then opening bracket , use one
        if(cl>0 && op<cl){
            str.push_back(')');
            genParenth(op, cl-1, str, ans);
            str.pop_back();
        }
        
    }
    
    vector<string> generateParenthesis(int n) {
        
        string str;
        vector<string> ans;
        
        genParenth(n, n, str, ans);
        
        return ans;
    }
};