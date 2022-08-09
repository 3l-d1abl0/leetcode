class Solution {
public:
    string removeDuplicateLetters(string s) {
        
        int N = s.size();
        
        vector<bool> processed(26, false);
        vector<int> lastIndex(26, -1);
        
        for(int i=0; i<N; i++){
            lastIndex[s[i]-'a'] = i;
        }
        
        stack<char> st;
        for(int i=0; i<N; i++){
            
            if(processed[s[i]-'a']) continue;

            while(!st.empty() && st.top()> s[i] && lastIndex[st.top()-'a'] > i){
                    //if the stack top  exists later in the string
                    //process it later
                    processed[st.top()-'a'] = false;
                    st.pop();
            }
            
                processed[s[i]-'a'] = true;
                st.push(s[i]);
            
        }//for
        
        
        //return "aqs";
        
        string ans ="";
        while(!st.empty()){
            ans +=st.top();
            st.pop();
        }
        
        
        reverse(ans.begin(), ans.end());
        
        
        
        //cout<<ans<<endl;
        return ans;
    }
};