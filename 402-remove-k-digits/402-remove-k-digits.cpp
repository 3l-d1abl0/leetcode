class Solution {
public:
    string removeKdigits(string num, int k) {
     
        
        stack<char> st;
        
        for(int i=0; i<num.size(); i++){
            
            while(!st.empty() && st.top() > num[i] && k>0){
                
                st.pop();
                k--;
            }
            
            if(st.empty() && num[i]=='0')
                continue;
            
            st.push(num[i]);
        }
        
        while(!st.empty() && k>0){
            st.pop();
            k--;
        }
        
        string ans ="";
        
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        
        if(ans =="")    return "0";
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};