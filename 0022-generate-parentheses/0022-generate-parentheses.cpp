class Solution {
public:
    
    void genParenth(int op, int cl, string str, vector<string> &ans , int N){
        
        if(op==0 && cl==0){
            ans.push_back(str);
            return;
        }
        
        if(op>0){
            str.push_back('(');
            genParenth(op-1, cl, str, ans , N);
            str.pop_back();
        }
        
        if(cl>0 && op<cl){
            str.push_back(')');
            genParenth(op, cl-1, str, ans , N);
            str.pop_back();
        }
        
    }
    
    vector<string> generateParenthesis(int n) {
        
        string str;
        vector<string> ans;
        
        genParenth(n, n, str, ans , n);
        
        return ans;
    }
};