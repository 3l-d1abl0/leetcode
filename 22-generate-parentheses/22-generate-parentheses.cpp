class Solution {
public:
    
    void genPar(string &str, int op, int cl, vector<string> &strList){
        
        
        if(op==0 && cl ==0){
            strList.push_back(str);
            return;
        }
        
        //cout<<str<<endl;
        
        if(op>0){
            
            str.push_back('(');
            genPar(str, op-1, cl, strList);
            str.pop_back();
        }
        
        if(cl>0 && op<cl){
            str.push_back(')');
            genPar(str, op, cl-1, strList);
            str.pop_back();
        }
        
    }
    
    vector<string> generateParenthesis(int n) {
        
        vector<string> strList;
        string str;
        genPar(str, n, n, strList);
        
        
        return strList;
    }
};