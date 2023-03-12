class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        
        stack<int> st;
        
        for(int ele: asteroids){
            
            if(ele>=0){
                st.push(ele);
            }else{
                
                
                while(!st.empty() && st.top() >=0 && ele<0 && abs(st.top()) < abs(ele)){
                    
                    st.pop();
                    
                }
                
                //either the stack is empty or the the top is > equal to ele
                if(st.empty() || st.top()<0){
                    st.push(ele);
                }else if(st.top() == abs(ele)){
                    st.pop();
                }
                
            }
        }//for
        
        
        int sz = st.size();
        //cout<<sz<<endl;
        vector<int> ans (sz);
        
        while(!st.empty()){
            ans[--sz] = st.top();
            
            st.pop();
        }
        
        
        return ans;
    }
};