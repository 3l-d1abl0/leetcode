class Solution {
public:

    string method1(string s){

        stack<tuple<char, int>> st;

        int N = s.size();

        for(int idx=0; idx<N; idx++){

            if(s[idx]=='('){
                st.push({s[idx], idx});
            }else if(s[idx]==')'){

                if ( !st.empty()){
                    auto [ ch, id ] = st.top();
                    
                    if(  ch == '(' )
                        st.pop();
                    else
                        st.push({s[idx], idx});
                }else
                    st.push({s[idx], idx});

                cout<<"idx : "<<idx<<endl;
            }

            //ignore if alphabets
        }

        int extraBraces = st.size();
        cout<<"Extra Braces: "<<extraBraces<<endl;
        while(!st.empty()){

            auto [_, idx] = st.top();
            s[idx] = '*';//place Marker
            

            st.pop();

        }

        int j=0;
        for(int i=0; i<N; i++){

            if(s[i]=='*')
                continue;

            s[j]= s[i];
            j++;
        }


        return s.substr(0, j);
    }

    string minRemoveToMakeValid(string s) {
        

        //1. Stak - TC: O(N) SC: O(N)
        return method1(s);

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