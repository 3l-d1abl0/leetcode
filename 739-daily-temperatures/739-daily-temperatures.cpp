class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
       
        stack<int> st;
        
        int sz = temp.size();
        
        vector<int> res;
        for(int i= sz-1; i>=0 ; i--){
            
            
            while(!st.empty() && temp[i]>= temp[st.top()]){
                st.pop();
            }
            
            if(st.empty()){
                res.push_back(0);
            }else{
                res.push_back(st.top() - i);
            }
            
            
            st.push(i);
        }//for
        
        
        reverse(res.begin(), res.end());
        
        return res;
    }
};