class Solution {
public:
        //#include<set>    
        set<char> symbols {'+','-','*','/'};

    
    void processSymbol(char sign, int num, stack<int> &st){
        
        //cout<<"adding "<<sign<<" "<<num<<" to stack "<<endl;
        
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
        
        /*
            for * amd /
            current number operates with the earlier nuber in stack
        */
            
    }
    
    pair<int, int> solve(string &s, int idx){
        /*
            The number is always preceded by a Sign,
            by default we start with +
        */
        int N = s.size(), num =0;
        char sign = '+';
        
        stack<int> st;
        
        
        for(int i=idx; i<N; i++){
            
            
            char symbol = s[i];
            
            if(symbol>=48 && symbol<=57){//number
                num = (num*10) + (symbol-'0');
            }else if(symbols.find(symbol)!=symbols.end()){
                //new symbol encountered, process (the symbol, the number ) so far
                processSymbol(sign, num, st);
                sign = symbol;//capture the new symbol
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
                
                //cout<<sum<<" "<<i<<endl;
                return {sum, i};
                //i is the postion of closing bracket whenere the current expression ends
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
        
        /*
            ASCII
            0-9 -> 48_57
            A-Z -> 65_90
            a-z -> 97_122

            solve() -> solves the (experssion)
            1st solve() call, calculates exp + (exp) +exp
        
        */
        
        pair<int, int> pp = solve(s, 0);
        ////second is the postion of closing bracket whenere the current expression ends
        
        cout<<pp.first<<" "<<pp.second<<endl;
        
        return pp.first;
    }
};