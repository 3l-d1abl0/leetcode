class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        stack<int> st;
        
        for(int i=0; i<tokens.size(); i++){
            
            if(tokens[i]!= "+" && tokens[i]!= "-" && tokens[i]!= "*" && tokens[i]!= "/"){
                int num = 0;
                stringstream geek(tokens[i]);
                geek >>num;
                //cout<<num<<"1"<<tokens[i]<<endl;
                st.push(num);
            }else{
                int n2 = st.top(); st.pop();
                int n1 = st.top(); st.pop();
                
                //cout<<n1<<"&"<<n2<<endl;
                if(tokens[i] == "+") st.push(n1+n2);
                if(tokens[i] == "-") st.push(n1-n2);
                if(tokens[i] == "/") st.push(n1/n2);
                if(tokens[i] == "*") st.push(n1*n2);
            }
        }
        
        
        return st.top();
    }
};