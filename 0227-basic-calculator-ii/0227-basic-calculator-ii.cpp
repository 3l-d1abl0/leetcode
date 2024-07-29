class Solution {
public:
    
        set<char> symbols {'+','-','*','/'};

    
    void processSymbol(char sign, int num, stack<int> &st){
        
        cout<<"adding "<<sign<<" "<<num<<" to stack "<<endl;
        
        if (sign=='+'){
            st.push(num);
        }else if(sign=='-'){
            st.push(-num);
        }else if(sign=='*'){
            int top = st.empty() ? 0: st.top();
            st.pop();
            st.push(top*num);
        }else if(sign=='/'){
            int top = st.empty() ? 0: st.top();
            st.pop();
            st.push(top/num);
        }
            
    }
    
    pair<int, int> solve(string &s, int idx){
        
        int N = s.size(), num =0;
        char sign = '+';
        
        stack<int> st;
        
        
        for(int i=idx; i<N; i++){
            
            
            char symbol = s[i];
            
            if(symbol>=48 && symbol<=57){
                num = (num*10) + (symbol-'0');
            }else if(symbols.find(symbol)!=symbols.end()){
                //new symbol encountered, process the number, symbol so far
                processSymbol(sign, num, st);
                sign = symbol;
                num =0;
            }else if(symbol=='('){
                pair<int,int> pp = solve(s, i+1);
                i = pp.second;
                num = pp.first;
            }else if(symbol ==')'){
                processSymbol(sign, num, st);
                
                int sum=0;
                while(!st.empty()){
                    sum+=st.top();
                    st.pop();
                }
                
                cout<<sum<<" "<<i<<endl;
                return {sum, i};
            }
            
            
        }//for
        
        int sum=0;
        //cout<<sign<<num<<" sz:"<<st.top()<<endl;
        processSymbol(sign, num, st);
        //cout<<sign<<num<<" sz:"<<st.top()<<endl;
        while(!st.empty()){
            cout<<"T: "<<st.top()<<endl;
            sum+=st.top();
            st.pop();
        }
        
        
        
        return {sum, N};
        
    }
    
    int calculate(string s) {
                pair<int, int> pp = solve(s, 0);
        
        cout<<pp.first<<" "<<pp.second<<endl;
        
        return pp.first;
    }
};