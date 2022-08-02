class Solution {
public:
    
    unordered_map<char, char> mp  { {'(',')'}, {'[',']'}, {'{','}'}, {')','('}, {']','['}, {'}','{'} };
    bool isValid(string s) {
        
        
        stack<char> st;
        
        for(char ch: s){
            
            
            if(ch=='(' || ch =='[' || ch== '{')
                st.push(ch);
            
            if(ch==')' || ch==']' || ch=='}'){
                if(st.size()!=0 && st.top() == mp[ch])
                    st.pop();
                else
                    return false;
            }
        }
        
        return st.empty();
    }
};