class Solution {
public:
    
        long long method2(vector<int> &mh){
        
        int N = mh.size();
        long long cumSum;
        
        stack<pair<int, long long>> st;
        
        //peak on right, descending from left to right
        vector<long long> r2ldes(N, 0);
        
        for(int i=0; i<N; i++){
        
            while(!st.empty() && mh[st.top().first] >= mh[i]){
                st.pop();
            }
            
            
            
            if(st.empty())
                cumSum = 1LL *(i+1) * mh[i];
            else
                cumSum =  st.top().second + 1LL*(i-st.top().first)*mh[i];
        
            
            st.push({i, cumSum});
            r2ldes[i] = cumSum;
            
        }
        
        vector<long long > l2rdes(N, 0);
        stack<pair<int, long long>> st2;
        
        
        for(int i=N-1; i>=0; i--){
            
            while(!st2.empty() && mh[st2.top().first]>= mh[i]){
                st2.pop();
            }
            
            if(st2.empty())
                cumSum = 1LL* (N-i) * mh[i];
            else
                cumSum = st2.top().second +  1LL*(st2.top().first-i)*mh[i] ;
            
            st2.push({i, cumSum});
            l2rdes[i] = cumSum;
            //cout<<" l2r"<<l2rdes[i]<<endl;
        }//for N-1 -> 0
        
        long long int maxSum =0;
        
        /*
        for(int ele: r2ldes)
            cout<<ele<<" ";
        cout<<endl;
        for(int ele: l2rdes)
            cout<<ele<<" ";
        
        cout<<endl;*/
        for(int i=0; i<N; i++){
            maxSum = max(maxSum, r2ldes[i]+l2rdes[i]-mh[i]);
            
            //cout<<r2ldes[i]+l2rdes[i]-mh[i]<<endl;
        }
        
        
        return maxSum;
    }
    
    
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        
            //2. Useing Stack - O(N)
            return method2(maxHeights);
        
    }
};