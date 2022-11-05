class Solution {
public:
    string minRemoveToMakeValid(string s) {
        
        int N = s.size();
        
        int open =0, close =0;
        
        for(int i=0; i<N; i++){
            
            if(s[i]=='(')
                open++;
            else{
                
                if(s[i]==')'){
                    if(open==0) s[i] ='?';
                    else open--;
                }
            }
            
            
            if(s[N-1-i]==')')
                close++;
            else{
                
                if(s[N-1-i]=='('){
                    if(close==0) s[N-1-i] ='?';
                    else close--;
                }
            }
            
            
            
            
        }//for
        
        
        string ans;
        for(char ch:s){
            if(ch=='?')
                continue;
            
            ans.push_back(ch);
        }
        
        
        return ans;
    }
};