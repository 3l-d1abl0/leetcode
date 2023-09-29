class Solution {
public:
    int MOD = 1e9+7;
    int minn;
    
    int sumSubarrayMins(vector<int>& arr) {
    
        
        /*
            1. For every 'i' fidn the just lesser number on iots left and right
            That 'i' is minimum in that left-right Range.
            
            2. Find the number of sub ranges in left-right which contains 'i'
            'i' will be the minimum in all the subranges.
            
            3. 
        
        */
        
        int N = arr.size(); 
        vector<long int> left(N);
        vector<long int> right(N);
        
        //If no greater element founf on left and right
        for(int i=0; i<N; i++){
            left[i] =(i+1);
            right[i]= N-i;
        }
        
        //left 1->2->3->4
        //right 4->3->2->1
        
        stack<int> st;
        
        
        for(int i=0; i<arr.size(); i++){
            /*
            If 'i' is less than [st.top()]
            for st.top() 'i' is the leser element
            */
            while(!st.empty() && arr[st.top()] >arr[i]){
                right[st.top()] = i - st.top();
                st.pop();
            }
            
            /* 'i' is greater than st.top()
                so for 'i' , st.top() is the leser element on its left
            */
            if(!st.empty())
                left[i] = i-st.top();
            
            st.push(i);
        }
        
        
        /*
            eg:
            2 9 7 8 [3] 4 6 1
            
            for element 3, left-min : 2, right-min: 1
            
            len [9-3] = 4 (M)
            len [3-6] = 3 (N)
            
            len [9-6] = M+N-1
            
            Totla number of Subarray in the range M+N-1 which does not contain 3:
            
            [9 7 8] 3 [4 6]
            (M-1)       (N-1)
            
            ((M-1) * M) /2      + ((N-1)*N)/2   ------ (I)
        
            Total number of subarray where 3 is the minimum in the range M+N-1
            
            = (M+n-1) (M+N)  /2            - (I) 
            = boils down to M*N
        */
        int sum = 0;
        for(int i=0; i<arr.size(); i++){
            sum = (sum + (left[i]* arr[i]* right[i])%MOD)%MOD;
        }
        
        return sum;
    }
    
};
