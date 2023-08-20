class Solution {
public:
    int totalSteps(vector<int>& nums) {
        
        int N = nums.size();
        
        stack<pair<int, int>> st;
        int cnt=0, maxCnt=0;
        
        for(int i=N-1; i>=0; i--){
            
            //cout<<"Processing... "<<nums[i]<<endl;
            
            while(!st.empty() && nums[i] > st.top().first){
                
                
                //There is a wall on the right, check if its count is Greater
                //cout<<"Popping.. "<<st.top().first<<" "<<st.top().second<<endl;
                cnt = max(cnt+1, st.top().second);
                st.pop();
                
                
            }
            
            
            maxCnt = max(cnt, maxCnt);
            
            st.push({nums[i], cnt});
            
            cnt =0;
            
        }//for
        
        
        return maxCnt;
    }
};