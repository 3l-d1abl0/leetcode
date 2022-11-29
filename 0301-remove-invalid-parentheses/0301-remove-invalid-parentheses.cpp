class Solution {
public:
    unordered_set<string>st;
    void btr(string cur, string s, int left, int right, int pair, int index,int lt, int rt){
        //cout<<"inside"<<index<<endl;
        if(index==s.size()){
            //cout<<"found";
            if(left==0 && right==0 && pair==0)st.insert(cur);
            return;
        }
        if(s[index]!='(' && s[index]!=')'){
            cur+=s[index];
            btr(cur,s,left,right,pair,index+1,lt,rt);
            return;
        }
        if(s[index]=='('){
            if(left>0){
                btr(cur,s,left-1,right,pair,index+1,lt-1,rt);
            }
            if(rt) btr(cur+'(',s,left,right,pair+1,index+1,lt-1,rt);
            return;
        }
        if(right>0)btr(cur,s,left,right-1,pair,index+1,lt,rt-1);
        if(pair>0)btr(cur+')',s,left,right,pair-1,index+1,lt,rt-1);
    }
    vector<string> removeInvalidParentheses(string s) {
        /*ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);*/
        int left=0,lt=0;
        int right=0,rt=0; // lt and rt are used to store total number of ( and )
        for(auto c:s){
            if(c=='('){
                left++;
                lt++;
            }
            if(c==')'){
                rt++;
                if(left)left--;
                else right++;
            }
        }
        
        string cur="";
        btr(cur,s,left,right,0,0,lt,rt);
        //void btr(string cur, string s, int left, int right, int pair, int index,int lt, int rt)
        //cout<<st.size();
        return vector<string>(st.begin(),st.end());
    }
};