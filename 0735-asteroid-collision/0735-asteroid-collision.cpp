class Solution {
public:
    
    bool collision(int leftAst, int rightAst){
        
        if(leftAst > 0 && rightAst<0)
            return true;
        else
            return false;
    }
    
    vector<int> asteroidCollision(vector<int>& asteroids) {
        /*
            L R
            + + no collision
            - - no collision
            - + no collision
            + - collision
        */
        
        stack<int> st;
        int N = asteroids.size();
        
        for(int i=0; i<N ; i++){
            
            while(!st.empty() && collision(st.top(), asteroids[i])){
                
                if( abs(st.top()) >= abs(asteroids[i]) )
                    break;  //right asteroid gets destroyed
                else
                    st.pop();   //left asteroid gets destroyed
                
            }
            
            /*
                1. stack is empty no left asteroid
                2. no collision
                3. collision but both are equal
                3. collision but right gets destroyed
            */
            
            if(st.empty()){
                st.push(asteroids[i]);
            }else if (!collision(st.top(), asteroids[i])){
                st.push(asteroids[i]);
            }else{
                if(abs(st.top())==abs(asteroids[i]))
                    st.pop();
            }
        }//for
        
        int sz = st.size();
        vector<int> ans(sz);
        
        while(!st.empty()){
            ans[--sz] = st.top();
            st.pop();
        }
        
        
        
        return ans;
    }
};