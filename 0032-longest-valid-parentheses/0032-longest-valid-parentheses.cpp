class Solution {
public:
    int longestValidParentheses(string s) {
        
        
        stack<int> st;
        int N= s.size();
        if(N==0)
            return N;
        
        int open =0, close=0;
        int ques=0;
        for(int i=0; i<N; i++){
            
            
            if(s[i]=='('){
                open++;
            }else{
                
                if(s[i]==')'){
                    
                    if(open==0){
                        s[i]='?';
                        ques++;
                    }else
                        open--;
                    
                }
                
            }//else
            
            
            if(s[N-i-1]==')'){
                close++;   
            }else{
                
                if(s[N-i-1]=='('){
                    
                    if(close==0){
                        s[N-i-1]='?';
                        ques++;
                    }else
                        close--;
                }
                
            }
        }//for
        
        int ctr=0, maxLen=0;
        for(int i=0; i<N; i++){
            if(s[i]=='?'){
                ctr=0;
            
            }else{
                ctr++;
                    maxLen = max(maxLen, ctr);
            }
        }//for
        
        
        return maxLen;
        
    }
};