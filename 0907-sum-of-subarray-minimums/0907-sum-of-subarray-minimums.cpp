class Solution {
public:
    int MOD = 1e9+7;
    int minn;
    
    int sumSubarrayMins(vector<int>& arr) {
        
        vector<long int> left(arr.size());
        vector<long int> right(arr.size());
        
        for(int i=0; i<arr.size(); i++){
            left[i] =(i+1);
            right[i]= arr.size()-i;
        }
        
        //left 1->2->3->4
        //right 4->3->2->1
        
        stack<int> st;
        
        
        for(int i=0; i<arr.size(); i++){
            
            while(!st.empty() && arr[st.top()] >arr[i]){
                right[st.top()] = i - st.top();
                st.pop();
            }
            
            if(st.empty()) left[i] = i+1;
            else left[i] = i-st.top();
            
            st.push(i);
        }
        
        int sum = 0;
        for(int i=0; i<arr.size(); i++){
            sum = (sum + (left[i]* arr[i]* right[i])%MOD)%MOD;
        }
        
        return sum;
    }
    
};
