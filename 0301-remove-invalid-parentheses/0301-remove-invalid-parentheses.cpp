class Solution {
public:
    
    void recur(int idx, string &s, string str, unordered_set<string> &st, int extraLeft, int totalLeft, int pair, int extraRight, int totalRight ){
        
        if(idx== s.size()){
            if(extraLeft==0 && extraRight==0 && pair==0)
                st.insert(str);
            
            return;
        }
        
        //anyhting apart fron ( and ), , just add
        if(s[idx]!='(' && s[idx]!=')')
            return recur(idx+1, s, str+s[idx], st, extraLeft, totalLeft, pair, extraRight, totalRight );
        
        
        if(s[idx]=='('){
            
            if(extraLeft){
                recur(idx+1, s, str, st, extraLeft-1, totalLeft-1, pair, extraRight, totalRight );
            }
            
            if(totalRight)  //if there are right backets remaining, process a left bracket
                return recur(idx+1, s, str+s[idx], st, extraLeft, totalLeft-1, pair+1, extraRight, totalRight );
            
        }
        
        if(s[idx]==')'){
            
            if(extraRight){
                recur(idx+1, s, str, st, extraLeft, totalLeft, pair, extraRight-1, totalRight-1 );
            }
            
            if(pair)
                return recur(idx+1, s, str+s[idx], st, extraLeft, totalLeft, pair-1, extraRight, totalRight-1 );
        }
        
        
    } 
    
    vector<string> removeInvalidParentheses(string s) {
        
        int extraLeft =0, totalLeft=0;
        int extraRight =0, totalRight=0;
        
        for(char ch: s){
            if(ch=='('){
                totalLeft++;
                extraLeft++;
            }else if(ch==')'){
                
                if(extraLeft>0){
                    extraLeft--;
                }else{
                    extraRight++;
                }
                
                totalRight++;
            }
        }
        
        
        
        unordered_set<string> st;
        recur(0, s, "", st, extraLeft, totalLeft, 0, extraRight, totalRight );
        
        /*for(string str: st){
            cout<<str<<endl;
        }*/
        
        vector<string> ans(st.begin(), st.end());
        
        return ans;
    }
};