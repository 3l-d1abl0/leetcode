class Solution {
public:
    
    int method1(string &s){
        
        
        int N = s.size();
        stack<int> st;
        
        //open and close brakcets needed
        int open=0, close=0;
        
        for(int i=0; i<N; i++){
            
            
            if(s[i]=='('){
                
                st.push(s[i]);
                
            }else if(s[i]==')'){
                
                
                
                    
                    if(i+1<N && s[i+1]==')'){
                        
                        if(st.empty())
                            open++; //we need on opening bracket
                        else
                            st.pop();   //remove one left bracket
                    
                        i++;
                        
                    }else{  //)or string ended
                        
                        if(!st.empty()){//there is atleast one opening Bracket
                            close++;    //need on closing bracket to match that
                            st.pop();   //that opening bracket has beec considered
                        }else{
                            //there is no opening bracket
                            //need one closing bracket and opening Bracker
                            open++;
                            close++;
                        }
                    }//else
                    
                    
                        
                    
                
                
            }
            
            
        }//for
        
        
        //st represents number of opening brackets who needs pair
        
        return ( 2*st.size() )+open+close;
        
    }
    
    
    int method2(string &s){
        
        
        int N = s.size();
        
        //open and close brakcets needed
        int openBracket=0;
        //needed
        int open=0, close=0;
        
        for(int i=0; i<N; i++){
            
            
            if(s[i]=='('){
                
                openBracket++;
                
            }else if(s[i]==')'){
                
                
                
                    
                    if(i+1<N && s[i+1]==')'){
                        
                        if(openBracket==0)
                            open++; //we need on opening bracket
                        else
                            openBracket--;   //remove one left bracket
                    
                        i++;
                        
                    }else{  //)or string ended
                        
                        if(openBracket!=0){//there is atleast one opening Bracket
                            close++;    //need on closing bracket to match that
                            openBracket--;   //that opening bracket has beec considered
                        }else{
                            //there is no opening bracket
                            //need one closing bracket and opening Bracker
                            open++;
                            close++;
                        }
                    }//else
                    
                    
                        
                    
                
                
            }
            
            
        }//for
        
        
        //st represents number of opening brackets who needs pair
        
        return ( 2*openBracket )+open+close;
        
        
    }
    
    int minInsertions(string s) {
        
        //1 Stack
        //return method1(s);
        
        
        //2.Linear- without Stack
        return method2(s);
        
    }
};